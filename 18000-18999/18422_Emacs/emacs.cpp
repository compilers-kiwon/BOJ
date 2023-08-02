#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   Pos;    // first:row, second:col

#define MAX_SIZE    (100+1)
#define MAX_DIR     4
#define EMPTY       '.'

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

const static struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

bool    is_valid(int row,int col)
{
    return  (IN_RANGE(1,row,N)&&IN_RANGE(1,col,M));
}

int bfs(queue<Pos>& q)
{
    for(;!q.empty();q.pop())
    {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = cur_row+adj[d].d_row;
            int adj_col = cur_col+adj[d].d_col;

            if( !is_valid(adj_row,adj_col) || 
                    grid[adj_row][adj_col]==EMPTY )
            {
                continue;
            }

            q.push({adj_row,adj_col});
            grid[adj_row][adj_col] = EMPTY;
        }
    }

    return  0;
}

int find_rectangle(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] != EMPTY )
            {
                queue<Pos>  q;

                q.push({row,col});
                grid[row][col] = EMPTY;
                
                bfs(q);
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<find_rectangle()<<'\n';

    return  0;
}