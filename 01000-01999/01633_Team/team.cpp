#include    <iostream>

using namespace std;

#define MAX_SIZE        (1000+1)
#define NUM_OF_PLAYERS  15

typedef pair<int,int>   Ability;

static int  N,dp[MAX_SIZE][NUM_OF_PLAYERS+1][NUM_OF_PLAYERS+1];
static Ability  a[MAX_SIZE];

int input(void)
{
    for(N=0;cin>>a[N+1].first>>a[N+1].second;N++);
    return  0;
}

int simulate(void)
{
    int ret = 0;

    for(int cur_player=1;cur_player<=N;cur_player++)
    {
        int&    white = a[cur_player].first;
        int&    black = a[cur_player].second;

        dp[cur_player][1][0] = white;
        dp[cur_player][0][1] = black;

        for(int w=0;w<=NUM_OF_PLAYERS;w++)
        {
            for(int b=0;b<=NUM_OF_PLAYERS;b++)
            {
                int prev_player = cur_player-1;

                dp[cur_player][w][b] = 
                    max(dp[cur_player][w][b],dp[prev_player][w][b]);

                if( dp[prev_player][w][b] != 0 )
                {
                    if( w < NUM_OF_PLAYERS )
                    {
                        dp[cur_player][w+1][b] = 
                            max(dp[cur_player][w+1][b],dp[prev_player][w][b]+white);
                    }

                    if( b < NUM_OF_PLAYERS )
                    {
                        dp[cur_player][w][b+1] =
                            max(dp[cur_player][w][b+1],dp[prev_player][w][b]+black);
                    }
                }
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        ret = max(ret,dp[i][NUM_OF_PLAYERS][NUM_OF_PLAYERS]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}