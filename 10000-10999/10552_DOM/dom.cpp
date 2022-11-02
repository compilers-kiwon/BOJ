#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        0

int     N,M,P,adj_channel[MAX_SIZE];
bool    visited[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>P;

    for(int i=1;i<=N;i++)
    {
        int a,b;

        cin>>a>>b;

        if( adj_channel[b] == NONE )
        {
            adj_channel[b] = a;
        }
    }
}

int     dfs(int current,int cnt)
{
    // Check if there is a cycle.
    if( visited[current] == true )
    {
        return  -1;
    }

    visited[current] = true;

    return  ((adj_channel[current]==NONE)?
                cnt:dfs(adj_channel[current],cnt+1));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    cout<<dfs(P,0)<<'\n';

    return  0;
}