#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100+1)
#define START       1

int         N;
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N-1;i++)
    {
        int M;

        cin>>M;

        for(int j=1;j<=M;j++)
        {
            int C;

            cin>>C;
            connected[i].push_back(C);
        }
    }
}

bool    dfs(int current)
{
    if( current == N )
    {
        return  true;
    }

    if( visited[current] == true )
    {
        return  false;
    }

    visited[current] = true;

    for(int i=0;i<connected[current].size();i++)
    {
        int adj = connected[current][i];

        if( dfs(adj) == false )
        {
            return  false;
        }
    }

    visited[current] = false;

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(dfs(START)?"NO CYCLE":"CYCLE")<<'\n';

    return  0;
}