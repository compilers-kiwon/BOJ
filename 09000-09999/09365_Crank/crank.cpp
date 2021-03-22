#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10+1)

int     R,C,A,B;
int     grid[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{
    int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef pair<int,int>   Pos;    // first:row,second:col

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=MAX)

void    input(void)
{
    cin>>R>>C>>A>>B;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            cin>>grid[row][col];
            visited[row][col] = false;
        }
    }
}

void    bfs(void)
{
    queue<Pos>  pos_q;

    pos_q.push(make_pair(A,B));
    visited[A][B] = true;

    for(;!pos_q.empty();pos_q.pop())
    {
        int current_row,current_col;

        current_row = pos_q.front().first;
        current_col = pos_q.front().second;

        for(int d=UP;d<=RIGHT;d++)
        {
            int adj_row,adj_col;

            adj_row = current_row+adj[d].d_row;
            adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C)
                || visited[adj_row][adj_col]==true )
            {
                continue;
            }

            int&    current_height = grid[current_row][current_col];
            int&    adj_height = grid[adj_row][adj_col];

            if( current_height <= adj_height )
            {
                visited[adj_row][adj_col] = true;
                pos_q.push(make_pair(adj_row,adj_col));
            }
        }
    }
}

int     count_boundary(void)
{
    int ret = 0;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            if( visited[row][col] == false )
            {
                continue;
            }

            if( row==1 || row==R || col==1 || col==C )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        bfs();

        cout<<"Case #"<<t<<": "<<count_boundary()<<'\n';
    }

    return  0;
}