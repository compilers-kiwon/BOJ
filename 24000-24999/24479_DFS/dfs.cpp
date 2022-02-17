#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        0

int         N,M,R,visit_order[MAX_SIZE];
set<int>    connected[MAX_SIZE];

void    dfs(int current,int& order)
{
    visit_order[current] = order;
    order++;

    set<int>&   adj = connected[current];

    for(set<int>::iterator it=adj.begin();it!=adj.end();it++)
    {
        int adj_node = *it;

        if( visit_order[adj_node] == NONE )
        {
            dfs(adj_node,order);
        }
    }
}

void    input(void)
{
    cin>>N>>M>>R;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].insert(v);
        connected[v].insert(u);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n = 1;

    input();
    dfs(R,n);

    for(int i=1;i<=N;i++)
    {
        cout<<visit_order[i]<<'\n';
    }

    return  0;
}