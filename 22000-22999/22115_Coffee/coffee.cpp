#include    <iostream>

using namespace std;

#define MAX_COFFEE      (100+1)
#define MAX_CAFFEINE    (100000+1)

int N,K,c[MAX_COFFEE],dp[MAX_COFFEE][MAX_CAFFEINE];

void    input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>c[i];
    }
}

void    take_coffee(void)
{
    for(int i=1;i<=N;i++)
    {
        int&    current_caffeine = c[i];

        dp[i][current_caffeine] = 1;

        for(int caffeine=1;caffeine<=K;caffeine++)
        {
            int&    prev_coffee = dp[i-1][caffeine];

            if( prev_coffee == 0 )
            {
                continue;
            }

            if( dp[i][caffeine]==0 || prev_coffee<dp[i][caffeine] )
            {
                dp[i][caffeine] = prev_coffee;
            }

            if( caffeine+current_caffeine <= K )
            {
                dp[i][caffeine+current_caffeine] = prev_coffee+1;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    take_coffee();

    cout<<((dp[N][K]==0)?((K==0)?0:-1):dp[N][K])<<'\n';

    return  0;
}