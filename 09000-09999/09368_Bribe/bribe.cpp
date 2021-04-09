#include    <iostream>

using namespace std;

#define MAX_SIZE    16
#define MAX_MONEY   (1000+1)
#define TBD         -1.0

typedef pair<int,double>    Candidate;

int         n,c,m;
double      max_probability,dp[1<<MAX_SIZE][MAX_SIZE+1];
Candidate   candidate[MAX_SIZE];

double  get_dp(int contacted,int money,int required)
{
    double& ret = dp[contacted][required];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0.0;

    for(int i=0;i<n;i++)
    {
        if( (contacted&(1<<i)) != 0 )
        {
            continue;
        }

        if( candidate[i].first > money )
        {
            continue;
        }

        double  s,f;

        s = candidate[i].second*get_dp(contacted|(1<<i),money-candidate[i].first,required-1)/100.0;
        f = (100.0-candidate[i].second)*get_dp(contacted|(1<<i),money-candidate[i].first,required)/100.0;

        ret = max(ret,s+f);        
    }

    return  ret;
}

void    input(void)
{
    scanf("%d %d %d",&n,&c,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%d %lf",&candidate[i].first,&candidate[i].second);
    }
}

int     main(void)
{
    int T;

    scanf("%d",&T);

    for(;T>0;T--)
    {
        input();

        for(int row=0;row<(1<<n);row++)
        {
            fill(&dp[row][1],&dp[row][c+1],TBD);
            dp[row][0] = 1.0;
        }

        printf("%.6f\n",get_dp(0,m,c));
    }

    return  0;
}