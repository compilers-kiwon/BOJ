#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4

#define GRASS   '#'
#define EMPTY   '.'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     R,C;
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void    input(void)
{
    cin>>R>>C;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];
    }
}

void    dfs(int row,int col)
{
    grid[row][col] = EMPTY;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
        {
            continue;
        }

        if( grid[adj_row][adj_col] == GRASS )
        {
            dfs(adj_row,adj_col);
        }
    }
}

int     count_num_of_clumps(void)
{
    int ret = 0;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            if( grid[row][col] == GRASS )
            {
                ret++;dfs(row,col);
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<count_num_of_clumps()<<'\n';

    return  0;
}