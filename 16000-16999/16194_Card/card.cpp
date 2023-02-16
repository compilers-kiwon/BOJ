#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFF
#define TBD         -1

static int  N,P[MAX_SIZE],dp[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>P[i];
        dp[i] = TBD;
    }

    return  0;
}

int get_dp(int num_of_cards)
{
    int&    ret = dp[num_of_cards];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = INF;

    for(int i=1;num_of_cards-i>=0;i++)
    {
        int cost = get_dp(num_of_cards-i);

        if( cost != INF)
        {
            ret = min(ret,cost+P[i]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_dp(N)<<'\n';

    return  0;
}