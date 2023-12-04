#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef vector<int> Damage;
typedef struct{int n;vector<int> m;} State;

const static vector<Damage> d = {
    {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9}
};

const static int MAX_HP = 60;
const static int MAX_NUM_OF_MUTALISK = 3;
const static int NONE = 0;
const static int INF = 0x7FFFFFFF;

static int dp[MAX_HP+1][MAX_HP+1][MAX_HP+1];

static inline int get_hp_sum(const vector<int>& hp) {
    int ret = 0;
    for (int i=0;i<hp.size();i++) ret+=hp[i];
    return  ret;
}

void input(State& s)
{
    int N;

    cin>>N;
    s.n = 0;

    for (int i=1;i<=N;i++) {
        int scv;
        cin>>scv;
        s.m.push_back(scv);
    }

    for (;s.m.size()<MAX_NUM_OF_MUTALISK;){
        s.m.push_back(NONE);
    }
}

void init_dp(const State& s)
{
    const vector<int>& hp = s.m;

    for (int i=0;i<=MAX_HP;i++) {
        for (int j=0;j<=MAX_HP;j++) {
            for (int k=0;k<=MAX_HP;k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[hp[0]][hp[1]][hp[2]] = s.n;
}

int simulate(const State& init)
{
    queue<State> q;

    init_dp(init);
    q.push(init);

    for (;!q.empty();q.pop()) {
        State cur = q.front();
        
        if (get_hp_sum(cur.m) == 0) continue;

        for (int i=0;i<d.size();i++) {
            State next;
            const vector<int>& damage = d[i];
            
            next.n = cur.n+1;
            for (int j=0;j<MAX_NUM_OF_MUTALISK;j++) {
                next.m.push_back(max(0,cur.m[j]-damage[j]));
            }
            
            if (next.n < dp[next.m[0]][next.m[1]][next.m[2]]) {
                q.push(next);
                dp[next.m[0]][next.m[1]][next.m[2]] = next.n;
            }
        }
    }

    return  dp[0][0][0];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    State s;

    input(s);
    cout<<simulate(s)<<'\n';

    return  0;
}