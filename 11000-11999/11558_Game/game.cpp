#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

int     N,A[MAX_SIZE];
bool    visited[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        visited[i] = false;
    }
}

int     dfs(int i,int step)
{
    if( i == N )
    {
        return  step;
    }

    if( visited[i] == true )
    {
        return  0;
    }

    visited[i] = true;

    return  dfs(A[i],step+1);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<dfs(1,0)<<'\n';
    }

    return  0;
}