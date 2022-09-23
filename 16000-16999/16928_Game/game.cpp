#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    100
#define NONE        0
#define MAX_STEP    6

int N,M,grid[MAX_SIZE+1],dp[MAX_SIZE+1];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N+M;i++)
    {
        int x,y;

        cin>>x>>y;
        grid[x] = y;
    }
}

int     simulate(void)
{
    queue<int>  q;

    dp[1] = 1;
    q.push(1);

    for(;!q.empty();q.pop())
    {
        int current = q.front();

        for(int step=1;step<=MAX_STEP;step++)
        {
            int adj = min(current+step,MAX_SIZE);

            adj = ((grid[adj]!=NONE)?grid[adj]:adj);

            if( dp[adj]==NONE || dp[current]+1<dp[adj] )
            {
                q.push(adj);
                dp[adj] = dp[current]+1;
            }
        }

    }

    return  dp[MAX_SIZE]-1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}