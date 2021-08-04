#include    <iostream>

using namespace std;

#define MAX_VALUE   100000
#define MAX_SIZE    (50+1)
#define TBD         -1

int n,c[MAX_SIZE],dp[MAX_VALUE+1];

void    input(void)
{
    cin>>n;
    fill(&dp[1],&dp[MAX_VALUE+1],TBD);

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
}

int     get_dp(int value)
{
    int&    ret = dp[value];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = value;

    for(int i=1;i<=n;i++)
    {
        if( c[i] > value )
        {
            break;
        }

        ret = min(ret,get_dp(value-c[i])+1);
    }

    return  ret;
}

int     do_greedy(int value)
{
    int ret = 0;

    for(;value!=0;)
    {
         for(int i=n;i>=1;i--)
        {
            if( c[i] <= value )
            {
                ret += value/c[i];
                value %= c[i];

                break;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int w = -1;

    input();
    dp[0] = 0;

    for(int v=1;v<=MAX_VALUE;v++)
    {
        if( get_dp(v) != do_greedy(v) )
        {
            w = v;
            break;
        }
    }

    cout<<w<<'\n';

    return  0;
}