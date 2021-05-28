#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    500
#define INF         0x7FFFFFFF
#define EMPTY       -1

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3
#define MAX_DIR 4

#define rotate(d,s)         (((d)+(s))%MAX_DIR)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    // first:row, second:col
typedef pair<int,Pos>   State;  // first:-num_of_rotations, second:Pos
const struct{int d_row,d_col;} adj[MAX_DIR] ={{-1,0},{0,1},{1,0},{0,-1}};

int     m,n,dp[MAX_SIZE][MAX_SIZE],grid[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>m>>n;

    for(int row=0;row<m;row++)
    {
        char    buf[MAX_SIZE+1];

        cin>>buf;

        for(int col=0;col<n;col++)
        {
            const char& c = buf[col];

            dp[row][col] = INF;
            grid[row][col] = (c=='N')?NORTH:(c=='E')?EAST:(c=='S')?SOUTH:(c=='W')?WEST:EMPTY;
        }
    }
}

int     move_to_competition_hall(void)
{
    priority_queue<State>   state_q;

    dp[0][0] = 0;
    state_q.push(make_pair(0,make_pair(0,0)));

    for(;!state_q.empty();)
    {
        int current_num_of_rotations = -state_q.top().first;
        int current_row = state_q.top().second.first;
        int current_col = state_q.top().second.second;

        state_q.pop();

        if( current_row==m-1 && current_col==n-1 )
        {
            break;
        }

        const int   current_dir = grid[current_row][current_col];

        if( current_dir == EMPTY )
        {
            continue;
        }

        for(int r=0;r<MAX_DIR;r++)
        {
            int adj_row,adj_col;

            adj_row = current_row+adj[rotate(current_dir,r)].d_row;
            adj_col = current_col+adj[rotate(current_dir,r)].d_col;

            if( !IN_RANGE(0,adj_row,m-1) || !IN_RANGE(0,adj_col,n-1) )
            {
                continue;
            }

            if( current_num_of_rotations+r < dp[adj_row][adj_col] )
            {
                dp[adj_row][adj_col] = current_num_of_rotations+r;
                state_q.push(make_pair(-dp[adj_row][adj_col],make_pair(adj_row,adj_col)));
            }
        }
    }

    return  (dp[m-1][n-1]==INF?-1:dp[m-1][n-1]);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<move_to_competition_hall()<<'\n';

    return  0;
}