#include    <iostream>

using namespace std;

#define MAX_VOLUME_OF_OXYGEN    21
#define MAX_VOLUME_OF_NITROGEN  79
#define MAX_NUM_OF_CYLINDERS    1000

typedef struct{int t,a,w;}  Cylinder;

int         t,a,n;
int         dp[MAX_NUM_OF_CYLINDERS+1][MAX_VOLUME_OF_OXYGEN+1][MAX_VOLUME_OF_NITROGEN+1];
Cylinder    c[MAX_NUM_OF_CYLINDERS+1];

void    input(void)
{
    cin>>t>>a>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>c[i].t>>c[i].a>>c[i].w;
    }
}

void    get_dp(void)
{
    for(int i=1;i<=n;i++)
    {
        int&    current_oxygen = c[i].t;
        int&    current_nitrogen = c[i].a;
        int&    current_weight = c[i].w;

        dp[i][current_oxygen][current_nitrogen] = current_weight;
        
        for(int o=1;o<=MAX_VOLUME_OF_OXYGEN;o++)
        {
            for(int ni=1;ni<=MAX_VOLUME_OF_NITROGEN;ni++)
            {
                int&    prev_weight = dp[i-1][o][ni];

                if( prev_weight == 0 )
                {
                    continue;
                }

                if( dp[i][o][ni]==0 || prev_weight<dp[i][o][ni] )
                {
                    dp[i][o][ni] = prev_weight;
                }

                int next_oxygen = min(MAX_VOLUME_OF_OXYGEN,current_oxygen+o);
                int next_nitrogen = min(MAX_VOLUME_OF_NITROGEN,current_nitrogen+ni);

                if( dp[i][next_oxygen][next_nitrogen]==0
                    || prev_weight+current_weight<dp[i][next_oxygen][next_nitrogen] )
                {
                    dp[i][next_oxygen][next_nitrogen] = prev_weight+current_weight;
                }
            }
        }
    }
}

int     get_min_weight(void)
{
    int ret = 0x7FFFFFFF;

    for(int o=t;o<=MAX_VOLUME_OF_OXYGEN;o++)
    {
        for(int ni=a;ni<=MAX_VOLUME_OF_NITROGEN;ni++)
        {
            if( dp[n][o][ni]!=0 && dp[n][o][ni]<ret )
            {
                ret = dp[n][o][ni];
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_dp();

    cout<<get_min_weight()<<'\n';

    return  0;
}