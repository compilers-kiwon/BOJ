#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (1000+1)
#define TBD         -1

int         K,M,P,dp[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>K>>M>>P;

    for(int i=1;i<=M;i++)
    {
        dp[i] = TBD;
        connected[i].clear();
    }

    for(int i=1;i<=P;i++)
    {
        int A,B;

        cin>>A>>B;
        connected[B].push_back(A);
    }
}

int     get_dp(int n)
{
    int&    ret = dp[n];

    if( ret != TBD )
    {
        return  ret;
    }

    if( connected[n].empty() )
    {
        return  (ret=1);
    }

    int max_value,cnt;

    max_value = cnt = 0;

    for(int i=0;i<connected[n].size();i++)
    {
        int&    prev = connected[n][i];
        int     s = get_dp(prev);

        if( s >= max_value )
        {
            if( s > max_value )
            {
                cnt = 0;
            }

            max_value = s;
            cnt++;
        }
    }

    if( cnt == 1 )
    {
        ret = max_value;
    }
    else
    {
        ret = max_value+1;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<K<<' '<<get_dp(M)<<'\n';
    }

    return  0;
}