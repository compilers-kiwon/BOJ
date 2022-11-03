#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4

#define EMPTY   '.'
#define ICE     '#'

int     N;
bool    visited[MAX_SIZE][MAX_SIZE];
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_ice(r,c)         (grid[(r)][(c)]==ICE)

void    dfs(int row,int col,int& size_of_blob,int& perimeter)
{
    size_of_blob++;perimeter+=MAX_DIR;
    visited[row][col] = true;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        if( is_ice(adj_row,adj_col) == true )
        {
            perimeter--;

            if( visited[adj_row][adj_col] == false )
            {
                dfs(adj_row,adj_col,size_of_blob,perimeter);
            }
        }
    }
}

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_size_of_blob,perimeter_of_max_blob;

    input();
    max_size_of_blob = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( is_ice(row,col) == true 
                    && visited[row][col] == false )
            {
                int size_of_blob,perimeter;

                size_of_blob = perimeter = 0;
                dfs(row,col,size_of_blob,perimeter);

                if( max_size_of_blob <= size_of_blob )
                {
                    if( max_size_of_blob == size_of_blob )
                    {
                        perimeter = min(perimeter,perimeter_of_max_blob);
                    }

                    max_size_of_blob = size_of_blob;
                    perimeter_of_max_blob = perimeter;
                }
            }
        }
    }

    cout<<max_size_of_blob<<' '<<perimeter_of_max_blob<<'\n';

    return  0;
}