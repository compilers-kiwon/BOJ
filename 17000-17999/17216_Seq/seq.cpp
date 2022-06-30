#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define TBD         -1

int N,A[MAX_SIZE],dp[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        dp[i] = TBD;
    }
}

int     get_dp(int pos)
{
    int&    ret = dp[pos];

    if( ret != TBD )
    {
        return  ret;
    }

    int prev_max_dp = 0;

    for(int i=pos-1;i>=1;i--)
    {
        if( A[i] > A[pos] )
        {
            prev_max_dp = max(prev_max_dp,get_dp(i));
        }
    }

    ret = prev_max_dp+A[pos];

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_sum = 0;

    input();

    for(int i=1;i<=N;i++)
    {
        max_sum = max(max_sum,get_dp(i));
    }

    cout<<max_sum<<'\n';

    return  0;
}