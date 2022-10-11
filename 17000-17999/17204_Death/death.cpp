#include    <iostream>

using namespace std;

#define MAX_SIZE    150
#define NONE        -1
#define START       0

int     N,K,a[MAX_SIZE];
bool    visited[MAX_SIZE];

void    input(void)
{
    cin>>N>>K;

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
}

int     dfs(int n,int step)
{
    if( visited[n] == true )
    {
        return  NONE;
    }

    visited[n] = true;

    if( n == K )
    {
        return  step;
    }

    return  dfs(a[n],step+1);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<dfs(START,0)<<'\n';

    return  0;
}