#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define INF         0x7FFFFFFF

#define ROW_SIZE    2
#define MOVE_ROW(r) (((r)+1)%ROW_SIZE)

#define SAFE    '1'
#define DANGER  '0'

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,Pos>   State;  // first:-time,second:Pos

#define build_state(t,r,c)  make_pair(-(t),make_pair((r),(c)))

int     N,K,dp[ROW_SIZE][MAX_SIZE+1];
char    grid[ROW_SIZE][MAX_SIZE+2];

void    input(void)
{
    cin>>N>>K;

    for(int row=0;row<ROW_SIZE;row++)
    {
        cin>>&grid[row][1];
        grid[row][N+1] = SAFE;

        fill(&dp[row][1],&dp[row][N+2],INF);
    }
}

int     simulate(void)
{
    priority_queue<State>   pq;

    dp[0][1] = 0;
    pq.push(build_state(0,0,1));

    for(;!pq.empty();)
    {
        int current_time = -pq.top().first;
        int current_row = pq.top().second.first;
        int current_col = pq.top().second.second;

        pq.pop();

        if( current_col == N+1 )
        {
            return  1;
        }

        if( grid[current_row][current_col+1] == SAFE &&
                current_time+1 < dp[current_row][current_col+1] )
        {
            dp[current_row][current_col+1] = current_time+1;
            pq.push(build_state(current_time+1,current_row,current_col+1));
        }

        if( current_col-1 > current_time+1 
                && grid[current_row][current_col-1] == SAFE
                && current_time+1 < dp[current_row][current_col-1] )
        {
            dp[current_row][current_col-1] = current_time+1;
            pq.push(build_state(current_time+1,current_row,current_col-1));
        }

        if( grid[MOVE_ROW(current_row)][min(current_col+K,N+1)] == SAFE && 
                current_time+1 < dp[MOVE_ROW(current_row)][min(current_col+K,N+1)] )
        {
            dp[MOVE_ROW(current_row)][min(current_col+K,N+1)] = current_time+1;
            pq.push(build_state(current_time+1,MOVE_ROW(current_row),min(current_col+K,N+1)));
        }
    }

    return  0;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}