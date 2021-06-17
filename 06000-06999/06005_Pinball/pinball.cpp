#include    <iostream>

using namespace std;

#define MAX_SIZE    (25+1)
#define TBD         -1

int R,X[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>R;

    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>X[i][j];
            dp[i][j] = TBD;
        }
    }
}

int     get_dp(int row,int col)
{
    int&    ret = dp[row][col];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = max(get_dp(row-1,col),get_dp(row-1,col-1))+X[row][col];

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_score = TBD;

    input();

    for(int col=1;col<=R;col++)
    {
        max_score = max(max_score,get_dp(R,col));
    }

    cout<<max_score<<'\n';

    return  0;
}