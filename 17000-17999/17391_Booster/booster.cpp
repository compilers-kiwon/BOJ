#include    <iostream>

using namespace std;

#define MAX_SIZE    (300+1)
#define TBD         -1
#define INF         (MAX_SIZE*MAX_SIZE)

int N,M,a[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>a[row][col];
            dp[row][col] = TBD;
        }
    }
}

int     get_dp(int current_row,int current_col)
{
    int&    ret = dp[current_row][current_col];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = INF;

    for(int adj_col=current_col-1;adj_col>=1;adj_col--)
    {
        if( adj_col+a[current_row][adj_col] < current_col )
        {
            continue;
        }

        ret = min(ret,get_dp(current_row,adj_col)+1);
    }

    for(int adj_row=current_row-1;adj_row>=1;adj_row--)
    {
        if( adj_row+a[adj_row][current_col] < current_row )
        {
            continue;
        }

        ret = min(ret,get_dp(adj_row,current_col)+1);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    dp[1][1] = 0;

    cout<<get_dp(N,M)<<'\n';

    return  0;
}