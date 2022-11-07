#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define ROOT        1

typedef pair<int,int>   Synapse;

int             N,M,parent[MAX_SIZE],num_of_operations;
bool            visited[MAX_SIZE];
queue<Synapse>  sq;
vector<int>     connected[MAX_SIZE];

int     find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;
        sq.push(make_pair(u,v));

        connected[u].push_back(v);
        connected[v].push_back(u);
    }
}

void    dfs(int current)
{
    if( visited[current] == true )
    {
        return;
    }

    visited[current] = true;

    for(int i=0;i<connected[current].size();i++)
    {
        dfs(connected[current][i]);
    }
}

void    build_connection(void)
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = i;

        if( visited[i] == false )
        {
            dfs(i);

            if( i != ROOT )
            {
                sq.push(make_pair(ROOT,i));
                num_of_operations++;
            }
        }
    }
}

void    remove_connection(void)
{
    for(;!sq.empty();sq.pop())
    {
        int u = sq.front().first;
        int v = sq.front().second;

        int pu = find_parent(u);
        int pv = find_parent(v);

        if( pu != pv )
        {
            parent[max(pu,pv)] = min(pu,pv);
        }
        else
        {
            num_of_operations++;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    
    build_connection();
    remove_connection();

    cout<<num_of_operations<<'\n';

    return  0;
}