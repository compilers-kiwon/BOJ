#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10000+1)
#define MAX_WIDTH   200
#define INF         0x7FFFFFFF

typedef pair<int,int>   Pos;    // first:stone,second:width
typedef pair<int,Pos>   State;  // first:-num_of_jump,second:Pos

int     N,M,dp[MAX_SIZE][MAX_WIDTH];
bool    small[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;
    
    for(int i=1;i<=N;i++)
    {
        fill(&dp[i][0],&dp[i][MAX_WIDTH],INF);
    }

    for(int i=1;i<=M;i++)
    {
        int s;

        cin>>s;
        small[s] = true;
    }
}

int     jump(void)
{
    priority_queue<State>   state_q;

    dp[1][0] = 0;
    state_q.push(make_pair(0,make_pair(1,0)));

    for(;!state_q.empty();)
    {
        int current_num_of_jump,current_stone,current_width;

        current_num_of_jump = -state_q.top().first;
        current_stone = state_q.top().second.first;
        current_width = state_q.top().second.second;

        state_q.pop();

        if( current_stone == N )
        {
            return  current_num_of_jump;
        }

        for(int d=-1;d<=1;d++)
        {
            int adj_width = max(current_width+d,1);
            int adj_stone = current_stone+adj_width;

            if( adj_stone>N || small[adj_stone]==true )
            {
                continue;
            }

            if( current_num_of_jump+1 < dp[adj_stone][adj_width] )
            {
                dp[adj_stone][adj_width] = current_num_of_jump+1;
                state_q.push(make_pair(-(current_num_of_jump+1),make_pair(adj_stone,adj_width)));
            }
        }
    }

    return  -1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<jump()<<'\n';

    return  0;
}