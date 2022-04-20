#include    <iostream>

using namespace std;

#define MAX_NUM_OF_PLAYERS  (99+1)
#define MAX_NUM_OF_PASSES   4

#define TBD -1

int J,dp[MAX_NUM_OF_PLAYERS][MAX_NUM_OF_PASSES+1];

void    init(void)
{
    cin>>J;

    for(int i=1;i<=J;i++)
    {
        fill(&dp[i][1],&dp[i][MAX_NUM_OF_PASSES+1],TBD);
    }
}

int     get_dp(int player,int turn)
{
    if( turn == 1 )
    {
        return  1;
    }

    int&    ret = dp[player][turn];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    for(int i=1;i<player;i++)
    {
        ret += get_dp(i,turn-1);
    }

    return  ret;
}

int     main(void)
{
    init();
    cout<<get_dp(J,4)<<'\n';

    return  0;
}