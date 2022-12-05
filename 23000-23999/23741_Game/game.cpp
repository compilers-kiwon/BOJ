#include    <iostream>
#include    <set>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

int         N,M,X,Y;
bool        visited[MAX_SIZE][MAX_SIZE];    // visited[Node][Step]
set<int>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>X>>Y;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].insert(v);
        connected[v].insert(u);
    }
}

void    simulate(void)
{
    queue<int>  q;

    q.push(X);
    visited[X][0] = true;

    for(int step=1;step<=Y&&!q.empty();step++)
    {
        for(int i=1,size=q.size();i<=size;i++,q.pop())
        {
            int         current = q.front();
            set<int>&   adj = connected[current];

            for(set<int>::iterator it=adj.begin();it!=adj.end();it++)
            {
                int adj_node = *it;

                if( visited[adj_node][step] == false )
                {
                    q.push(adj_node);
                    visited[adj_node][step] = true;
                }
            }
        }
    }
}

bool    print_candidates(void)
{
    bool    ret = false;

    for(int i=1;i<=N;i++)
    {
        if( visited[i][Y] == true )
        {
            cout<<i<<' ';
            ret = true;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    cout<<(print_candidates()?"\n":"-1\n");

    return  0;
}