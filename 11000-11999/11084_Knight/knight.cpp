#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE            (400+1)
#define INF                 0x7FFFFFFF
#define TBD                 -1
#define NONE                0
#define MAX_DIR             8
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define MOD(n)              ((n)%1000000009)

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,Pos>   State;  // first:num_of_step,second:Pos

int r,c,dp_for_step[MAX_SIZE][MAX_SIZE],dp_for_path[MAX_SIZE][MAX_SIZE];

const struct{
    int d_row,d_col;
} adj[MAX_DIR] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,2},{-1,-2},{1,2},{1,-2}};

void    init(void)
{
    cin>>r>>c;

    for(int row=1;row<=r;row++)
    {
        fill(&dp_for_path[row][1],&dp_for_path[row][c+1],TBD);
        fill(&dp_for_step[row][1],&dp_for_step[row][c+1],INF);
    }
}

bool    bfs(void)
{
    queue<State>   state_q;

    dp_for_step[1][1] = 0;
    state_q.push(make_pair(0,make_pair(1,1)));

    for(;!state_q.empty();state_q.pop())
    {
        int current_step,current_row,current_col;
        
        current_step = state_q.front().first;
        current_row = state_q.front().second.first;
        current_col = state_q.front().second.second;

        if( current_row==r && current_col==c )
        {
            continue;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;
            int adj_step = current_step+1;

            if( !IN_RANGE(1,adj_row,r) || !IN_RANGE(1,adj_col,c)
                || adj_step>=dp_for_step[adj_row][adj_col] )
            {
                continue;
            }

            dp_for_step[adj_row][adj_col] = adj_step;
            state_q.push(make_pair(adj_step,make_pair(adj_row,adj_col)));
        }
    }
    
    return  (dp_for_step[r][c]!=INF);
}

int     get_dp(int row,int col,int prev_step)
{
    int&    ret = dp_for_path[row][col];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,r) || !IN_RANGE(1,adj_col,c)
            || dp_for_step[adj_row][adj_col]!=prev_step )
        {
            continue;
        }

        ret = MOD(ret+get_dp(adj_row,adj_col,prev_step-1));
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    if( bfs() == false )
    {
        cout<<"None\n";
    }
    else
    {
        dp_for_path[1][1] = 1;
        cout<<dp_for_step[r][c]<<' '<<get_dp(r,c,dp_for_step[r][c]-1)<<'\n';
    }

    return  0;
}