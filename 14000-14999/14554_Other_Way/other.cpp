#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define MOD(n)      ((n)%1000000009)
#define INF         0x100000000000000
#define TBD         -1

typedef long long int   int64;
typedef pair<int,int64> Path;   // first:adj_pos,second:distance_to_adj_pos
typedef pair<int64,int> State;  // first:-total_distance,second:current_pos

int             N,M,S,E;
int64           dp[MAX_SIZE],cnt[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>S>>E;

    for(int i=1;i<=M;i++)
    {
        int     A,B;
        int64   C;

        cin>>A>>B>>C;

        connected[A].push_back(make_pair(B,C));
        connected[B].push_back(make_pair(A,C));
    }
}

void    move(void)
{
    priority_queue<State>   pq;

    for(dp[S]=0,pq.push(make_pair(0,S));!pq.empty();)
    {
        int64   current_dist = -pq.top().first;
        int     current_pos = pq.top().second;

        pq.pop();

        if ( current_dist>dp[current_pos] || current_pos==E )
        {
            continue;
        }
        
        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_pos = adj[i].first;
            int64   adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_pos] )
            {
                dp[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }
}

int64   get_cnt_of_path(int current_pos,int64 current_dist)
{
    int64&  ret = cnt[current_pos];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    vector<Path>&   adj = connected[current_pos];

    for(int i=0;i<adj.size();i++)
    {
        int     adj_pos = adj[i].first;
        int64   adj_dist = current_dist-adj[i].second;

        if( dp[adj_pos] == adj_dist )
        {
            ret = MOD(ret+get_cnt_of_path(adj_pos,adj_dist));
        }
    }

    return  ret;
}

void    init(void)
{
    fill(&dp[1],&dp[N+1],INF);
    fill(&cnt[1],&cnt[N+1],TBD);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init();move();

    cnt[S] = 1;
    cout<<get_cnt_of_path(E,dp[E])<<'\n';

    return  0;
}