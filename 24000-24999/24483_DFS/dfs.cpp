#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        -1

typedef long long int   int64;

int         N,M,R,depth[MAX_SIZE],visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>R;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    for(int i=1;i<=N;i++)
    {
        depth[i] = NONE;
        sort(connected[i].begin(),connected[i].end());
    }
}

void    dfs(int current,int d,int& order)
{
    if( depth[current] != NONE )
    {
        return;
    }

    depth[current] = d;
    visited[current] = order++;

    vector<int>&    adj = connected[current];

    for(int i=0;i<adj.size();i++)
    {
        dfs(adj[i],d+1,order);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int order = 1;

    input();
    dfs(R,0,order);

    int64   sum = 0;

    for(int i=1;i<=N;i++)
    {
        sum += (int64)depth[i]*(int64)visited[i];
    }

    cout<<sum<<'\n';

    return  0;
}