#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (16+1)

#define HORI        0
#define VERT        1
#define DIAG        2
#define MAX_STATE   3

typedef struct{int d_row,d_col;} Pos;

const Pos adj[MAX_STATE] = {{0,-1},{-1,0},{-1,-1}};
const vector<Pos> empty_pos[MAX_STATE] = {{},{},{adj[HORI],adj[VERT]}};
const vector<int> dependent[MAX_STATE] = {{HORI,DIAG},{VERT,DIAG},{HORI,VERT,DIAG}};

#define EMPTY   0
#define BLOCKED 1

#define TBD -1

static int  N,grid[MAX_SIZE][MAX_SIZE];
static int  dp[MAX_SIZE][MAX_SIZE][MAX_STATE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_available(row,col) \
    (IN_RANGE(1,(row),N)&&IN_RANGE(1,(col),N)&&grid[(row)][(col)]==EMPTY)

#define TRUE    1
#define FALSE   0

int is_empty_for_move(int row,int col,int state)
{
    int ret = TRUE;

    for(int i=0;i<empty_pos[state].size();i++)
    {
        int adj_row = row+empty_pos[state][i].d_row;
        int adj_col = col+empty_pos[state][i].d_col;

        if( grid[adj_row][adj_col] != EMPTY )
        {
            ret = FALSE;
            break;
        }
    }

    return  ret;
}

int get_dp(int row,int col,int state)
{
    int&    ret = dp[row][col][state];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    int adj_row = row+adj[state].d_row;
    int adj_col = col+adj[state].d_col;

    if( !is_available(adj_row,adj_col) || !is_empty_for_move(row,col,state) )
    {
        return  ret;
    }

    for(int i=0;i<dependent[state].size();i++)
    {
        ret += get_dp(adj_row,adj_col,dependent[state][i]);
    }
    
    return  ret;
}

int input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];

            for(int i=0;i<MAX_STATE;i++)
            {
                dp[row][col][i] = TBD;
            }
        }
    }

    dp[1][2][HORI] = 1;

    return  0;
}

int simulate(void)
{
    if( grid[N][N] == BLOCKED )
    {
        return  0;
    }

    int ret = 0;

    for(int i=0;i<MAX_STATE;i++)
    {
        ret += get_dp(N,N,i);
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