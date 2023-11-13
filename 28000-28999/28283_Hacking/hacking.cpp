#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef long long int   int64;

const static int MAX_NUM_OF_COMPUTERS = 500000+1;
const static int NONE = 0;

const static int64 INF = -1;
const static int64 TIME_FOR_INSTALLATION = 2;
const static int64 TIME_FOR_HACKING = 2;

static int N,M,X,Y;
static int64 A[MAX_NUM_OF_COMPUTERS];
static int64 safe_time[MAX_NUM_OF_COMPUTERS];
static queue<int> B;
static vector<int> connected[MAX_NUM_OF_COMPUTERS];

static inline int64 get_money_by_hacking(int computer_idx) {
    return  safe_time[computer_idx]
                /TIME_FOR_HACKING*A[computer_idx];
} 

void input(void)
{
    cin>>N>>M>>X>>Y;

    for (int i=1;i<=N;i++) {
        cin>>A[i];
    }

    for (int i=1;i<=M;i++) {
        int S,E;
        cin>>S>>E;

        connected[S].push_back(E);
        connected[E].push_back(S);
    }

    for (int i=1;i<=Y;i++) {
        int c;
        cin>>c;

        B.push(c);
        safe_time[c] = 1;
    }
}

void    simulate_to_install_sequrity(void)
{
    for (;!B.empty();B.pop()) {
        int cur_computer = B.front();
        int64 cur_time = safe_time[cur_computer];

        vector<int>&    adj = connected[cur_computer];

        for (int i=0;i<adj.size();i++) {
            int&    adj_computer = adj[i];

            if (safe_time[adj_computer] == 0) {
                safe_time[adj_computer]
                    = cur_time+TIME_FOR_INSTALLATION;
                B.push(adj_computer);
            }
        }
    }
}

int64   simulate_to_hack_computer(void)
{
    priority_queue<int64>   money;

    for (int i=1;i<=N;i++) {
        if (safe_time[i]==0 && A[i]!=0) {
            return  INF;
        }
        money.push(get_money_by_hacking(i));
    }

    int64   ret = 0;

    for (int i=1;i<=X;i++) {
        ret += money.top();
        money.pop();
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate_to_install_sequrity();
    cout<<simulate_to_hack_computer()<<'\n';

    return  0;
}