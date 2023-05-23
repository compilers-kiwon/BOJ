#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    50
#define MAX_DIR     6

static int  N,M;
static string   grid[MAX_SIZE];

const static struct{int d_row,d_col;} adj[2][MAX_DIR] = {
    {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}},
    {{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define IN_AREA(r,c)        (IN_RANGE(0,(r),N-1)&&IN_RANGE(0,(c),M-1))

int get_num_of_adj_beach(int row,int col)
{
    int ret = 0;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[row%2][d].d_row;
        int adj_col = col+adj[row%2][d].d_col;

        if( !IN_AREA(adj_row,adj_col) )
        {
            continue;
        }

        ret += (grid[adj_row][adj_col]=='.')?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for(int row=0;row<N;row++)
    {
        cin>>grid[row];
    }

    int num_of_beach = 0;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<M;col++)
        {
            if( grid[row][col] == '#' )
            {
                num_of_beach += get_num_of_adj_beach(row,col);
            }
        }
    }

    cout<<num_of_beach<<'\n';
    return  0;
}