#include    <iostream>

using namespace std;

#define MAX_SIZE    (600+1)
#define MAX_DIR     4

#define WALL    'X'
#define PERSON  'P'
#define START   'I'

int     N,M;
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    dfs(int row,int col,int& cnt)
{
    cnt += ((grid[row][col]==PERSON)?1:0);
    grid[row][col] = WALL;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        if( grid[adj_row][adj_col] != WALL )
        {
            dfs(adj_row,adj_col,cnt);
        }
    }
}

void    input(int& s_row,int& s_col)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == START )
            {
                s_row = row;
                s_col = col;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int row,col,cnt;

    input(row,col);

    cnt = 0;
    dfs(row,col,cnt);

    if( cnt != 0 )
    {
        cout<<cnt<<'\n';
    }    
    else
    {
        cout<<"TT\n";
    }

    return  0;
}