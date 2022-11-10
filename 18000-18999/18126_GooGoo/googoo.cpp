#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (5000+1)
#define NOT_VISITED -1
#define ENTERANCE   1

typedef long long int   int64;
typedef pair<int,int64> Path;   // first:adj_room,second:distance_to_adj_room

int             N;
int64           dist[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<N;i++)
    {
        int     A,B;
        int64   C;

        cin>>A>>B>>C;

        connected[A].push_back(make_pair(B,C));
        connected[B].push_back(make_pair(A,C));
    }
}

void    dfs(int current,int64 d)
{
    if( dist[current] != NOT_VISITED )
    {
        return;
    }

    dist[current] = d;

    vector<Path>&   adj = connected[current];

    for(int i=0;i<adj.size();i++)
    {
        int     adj_node = adj[i].first;
        int64   adj_dist = d+adj[i].second;

        dfs(adj_node,adj_dist);
    }
}

int64   get_max_distance(void)
{
    int64   ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret = max(ret,dist[i]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    fill(&dist[1],&dist[N+1],NOT_VISITED);

    dfs(ENTERANCE,0);
    cout<<get_max_distance()<<'\n';

    return  0;
}