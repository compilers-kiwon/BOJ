#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        -1

int         N,M,R,depth[MAX_SIZE];
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

void    dfs(int current,int d)
{
    if( depth[current] != NONE )
    {
        return;
    }

    depth[current] = d;

    vector<int>&    adj = connected[current];

    for(int i=0;i<adj.size();i++)
    {
        dfs(adj[i],d+1);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    dfs(R,0);

    for(int i=1;i<=N;i++)
    {
        cout<<depth[i]<<'\n';
    }

    return  0;
}