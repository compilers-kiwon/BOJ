#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (500+1)
#define NONE        0
#define ONE         1

void    input(int num_of_edges,vector<int> connected[])
{
    for(int i=1;i<=num_of_edges;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }
}

void    dfs(int current,vector<int> connected[],
                int prev,bool visited[],bool& cycle_flag)
{
    if( visited[current] == true )
    {
        cycle_flag = true;
        return;
    }

    visited[current] = true;

    vector<int>&    adj = connected[current];

    for(int i=0;i<adj.size();i++)
    {
        if( adj[i] != prev )
        {
            dfs(adj[i],connected,current,visited,cycle_flag);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int c=1;;c++)
    {
        int         n,m,num_of_trees;
        bool        visited[MAX_SIZE] = {false,};
        vector<int> connected[MAX_SIZE];

        cin>>n>>m;

        if( n==NONE && m==NONE )
        {
            break;
        }

        input(m,connected);
        num_of_trees = NONE;

        for(int i=1;i<=n;i++)
        {
            if( visited[i] == false )
            {
                bool    cycle = false;
                
                dfs(i,connected,NONE,visited,cycle);
                
                if( cycle == false )
                {
                    num_of_trees++;
                }
            }
        }

        cout<<"Case "<<c<<": ";

        switch(num_of_trees)
        {
            case    NONE:
                cout<<"No trees.\n";
                break;
            case    ONE:
                cout<<"There is one tree.\n";
                break;
            default:
                cout<<"A forest of "<<num_of_trees<<" trees.\n";
                break;
        }
    }

    return  0;
}