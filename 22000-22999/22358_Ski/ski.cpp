#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)
#define MAX_LIFT    (10+1)
#define TBD         -1
#define INF_MIN     -1000000000000000000

typedef long long int   int64;

typedef pair<int,int64> Path;
typedef pair<int,int>   Pos;
typedef pair<int64,Pos> State;

int             N,M,K,S,T;
int64           dp[MAX_SIZE][MAX_LIFT];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>K>>S>>T;

    for(int i=1;i<=M;i++)
    {
        int     a,b;
        int64   t;

        cin>>a>>b>>t;

        connected[b].push_back(make_pair(a,t));
        connected[a].push_back(make_pair(b,0));
    }
}

void    init_dp(void)
{
    for(int i=1;i<=N;i++)
    {
        fill(&dp[i][0],&dp[i][K+1],TBD);
    }
}

int64   get_dp(int current_pos,int lift)
{
    int64&  ret = dp[current_pos][lift];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = INF_MIN;

    vector<Path>&   adj = connected[current_pos];

    for(int i=0;i<adj.size();i++)
    {
        int&    adj_pos = adj[i].first;
        int64&  adj_time = adj[i].second;
        int64   prev_time;
        
        if( current_pos > adj_pos )
        {            
            if( (prev_time=get_dp(adj_pos,lift)) >= 0 )
            {
                ret = max(ret,prev_time+adj_time);
            }
        }
        else
        {
            if( lift>0 && (prev_time=get_dp(adj_pos,lift-1))>=0 )
            {
                ret = max(ret,prev_time+adj_time);
            }
        }
    }
    
    return  ret;
}

int64   simulate(void)
{
    int64   ret = -1;

    init_dp();
    dp[S][0] = 0;

    for(int i=0;i<=K;i++)
    {
        ret = max(ret,get_dp(T,i));
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}