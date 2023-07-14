#include    <iostream>

using namespace std;

#define ROW_SIZE    8
#define COL_SIZE    7
#define MAX_NUM     6

#define NUM_OF_PIECES   28

static bool used[MAX_NUM+1][MAX_NUM+1];
static bool filled[ROW_SIZE+1][COL_SIZE+1];
static int  grid[ROW_SIZE+1][COL_SIZE+1];

#define chr2int(c)          ((int)((c)-'0'))
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define UP      0
#define DWON    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int read_grid(void)
{
    for(int row=1;row<=ROW_SIZE;row++)
    {
        char    buf[COL_SIZE+2];

        cin>>&buf[1];

        for(int col=1;col<=COL_SIZE;col++)
        {
            grid[row][col] = chr2int(buf[col]);
        }
    }

    return  0;
}

int dfs(int row,int col,int num_of_used,int& cnt)
{
    if( num_of_used == NUM_OF_PIECES )
    {
        cnt++;
        return  0;
    }

    if( col > COL_SIZE )
    {
        row++;
        col = 1;
    }

    if( row > ROW_SIZE )
    {
        return  0;
    }

    if( filled[row][col] == true )
    {
        dfs(row,col+1,num_of_used,cnt);
        return  0;
    }

    for(int d=UP;d<=RIGHT;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,ROW_SIZE) || !IN_RANGE(1,adj_col,COL_SIZE) )
        {
            continue;
        }

        if( filled[adj_row][adj_col] == true )
        {
            continue;
        }

        int num1 = grid[row][col];
        int num2 = grid[adj_row][adj_col];

        if( used[num1][num2] == false )
        {
            used[num1][num2] = used[num2][num1] = true;
            filled[row][col] = filled[adj_row][adj_col] = true;

            dfs(row,col+1,num_of_used+1,cnt);

            filled[row][col] = filled[adj_row][adj_col] = false;
            used[num1][num2] = used[num2][num1] = false;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;

    read_grid();
    dfs(1,1,0,cnt);

    cout<<cnt<<'\n';
    return  0;
}