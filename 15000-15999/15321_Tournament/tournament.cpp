#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (500+1)
#define INF         0x7FFFFFFF
#define TBD         -1

int N,X[MAX_SIZE],dp[MAX_SIZE][MAX_SIZE],max_value[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>X[i];
        fill(&dp[i][1],&dp[i][N+1],TBD);
    }
}

void    get_max_value(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j++)
        {
            int&    prev_max_value = max_value[i][j-1];
            int&    current_max_value = max_value[i][j];
            int&    current_value = X[j];

            current_max_value = max(prev_max_value,current_value);
        }
    }
}

int     get_dp(int s,int e)
{
    int&    ret = dp[s][e];

    if( ret != TBD )
    {
        return  ret;
    }

    if( s == e )
    {
        ret = 0;
    }
    else
    {
        ret = INF;

        for(int i=s;i<e;i++)
        {
            int tmp;

            tmp = get_dp(s,i)+get_dp(i+1,e)+abs(max_value[s][i]-max_value[i+1][e]);
            ret = min(ret,tmp);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_max_value();

    cout<<get_dp(1,N)<<'\n';

    return  0;
}