#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)
#define MAX_DIR     4

int     N,M;
char    grid[MAX_SIZE][MAX_SIZE+1];
bool    visited[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;} 
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }
}

bool    is_cycle(int prev_row,int prev_col,
                    int current_row,int current_col)
{
    visited[current_row][current_col] = true;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = current_row+adj[d].d_row;
        int adj_col = current_col+adj[d].d_col;

        if( adj_row==prev_row && adj_col==prev_col )
        {
            continue;
        }

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        if( grid[current_row][current_col] != grid[adj_row][adj_col] )
        {
            continue;
        }

        if( visited[adj_row][adj_col] == true )
        {
            return  true;
        }

        if( is_cycle(current_row,current_col,adj_row,adj_col) == true )
        {
            return  true;
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=1;row<N;row++)
    {
        for(int col=1;col<M;col++)
        {
            if( visited[row][col]==false
                    && is_cycle(0,0,row,col)==true )
            {
                cout<<"Yes\n";
                return  0;
            }
        }
    }

    cout<<"No\n";
    return  0;
}