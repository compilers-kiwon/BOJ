#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define TBD         -1000000001
#define MIN_NUM     -2000000000

typedef long long int   int64;

int     n;
int64   w[MAX_SIZE],dp[MAX_SIZE];

void    input(void)
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        dp[i] = TBD;
    }

    dp[1] = w[1];
}

int64   get_dp(int64 pos)
{
    if( pos < 1 )
    {
        return  dp[1];
    }

    int64&  ret = dp[pos];

    if( ret != TBD )
    {
        return  ret;
    }

    int64   max_num = MIN_NUM;

    for(int i=1;i<=6;i++)
    {
        max_num = max(max_num,get_dp(pos-i));
    }

    ret = max_num+w[pos];

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_dp(n)<<'\n';

    return  0;
}