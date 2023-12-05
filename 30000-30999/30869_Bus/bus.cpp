#include    <iostream>
#include    <vector>

using namespace std;

typedef struct{int s,t,g;} Bus;

const static int MAX_SIZE = 500+1;
const static int TBD = -1;
const static int NONE = 0x7FFFFFFF;

static int  N,M,K;
static int  dp[MAX_SIZE][MAX_SIZE];
static vector<Bus> connected[MAX_SIZE];

static inline int get_depature_time(int arrival_time,int period) {
    return  ((arrival_time/period)*period+
                ((arrival_time%period==0)?0:period));
}

void input(void)
{
    cin>>N>>M>>K;

    for (int i=1;i<=M;i++) {
        int s,e,t,g;

        cin>>s>>e>>t>>g;
        connected[e].push_back({s,t,g});
    }

    for (int i=2;i<=N;i++) {
        fill(&dp[i][0],&dp[i][K+1],TBD);
    }
}

int get_dp(int s,int n)
{
    int&    ret = dp[s][n];

    if (ret != TBD) {
        return  ret;
    }

    const vector<Bus>&  adj = connected[s];

    ret = NONE;

    for (int i=0;i<adj.size();i++) {
        int prev_arrival_time;

        if ((prev_arrival_time=get_dp(adj[i].s,n)) != NONE) {
            ret = min(ret,get_depature_time(prev_arrival_time,adj[i].g)+adj[i].t);
        }

        if (n == 0) continue;

        if ((prev_arrival_time=get_dp(adj[i].s,n-1)) != NONE) {
            ret = min(ret,prev_arrival_time+adj[i].t);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_time = NONE;

    input();

    for (int i=0;i<=K;i++) {
        min_time = min(min_time,get_dp(N,i));
    }

    cout<<((min_time==NONE)?-1:min_time)<<'\n';
    return  0;
}