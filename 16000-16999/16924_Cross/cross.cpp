#include    <iostream>
#include    <vector>

using namespace std;

typedef struct{int r,c,s;}  Cross;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4
#define EMPTY       '.'
#define INF         0x7FFFFFFF
#define NONE        0

static int N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];
static bool visited[MAX_SIZE][MAX_SIZE+1];
static vector<Cross> cross;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define get_adj_row(r,d)    ((r)+adj[(d)].d_row)
#define get_adj_col(c,d)    ((c)+adj[(d)].d_col)

int get_continuous_length(int mid_row,int mid_col,int dir)
{
    int offset = 0;

    for(int row=get_adj_row(mid_row,dir),col=get_adj_col(mid_col,dir);
        IN_RANGE(1,row,N)&&IN_RANGE(1,col,M)&&grid[row][col]!=EMPTY;
        offset++,row=get_adj_row(row,dir),col=get_adj_col(col,dir));
    
    return  offset;
}

int find_cross(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == EMPTY )
            {
                continue;
            }

            int min_continous_len = INF;

            for(int d=0;d<MAX_DIR;d++)
            {
                min_continous_len = min(min_continous_len,
                                get_continuous_length(row,col,d));
            }

            if( min_continous_len == NONE )
            {
                continue;
            }

            cross.push_back({row,col,min_continous_len});
            visited[row][col] = true;

            for(int i=1;i<=min_continous_len;i++)
            {
                for(int d=0;d<MAX_DIR;d++)
                {
                    int adj_row = row+adj[d].d_row*i;
                    int adj_col = col+adj[d].d_col*i;

                    visited[adj_row][adj_col] = true;
                }
            }
        }
    }

    return  0;
}

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int all_visited(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col]!=EMPTY
                    && !visited[row][col] )
            {
                return  0;
            }
        }
    }

    return  1;
}

int print_cross(void)
{
    for(int i=0;i<cross.size();i++)
    {
        Cross&  c = cross[i];

        cout<<c.r<<' '<<c.c<<' '<<c.s<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    find_cross();

    if( all_visited()==0 || cross.empty() )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<cross.size()<<'\n';
        print_cross();
    }

    return  0;
}