#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define NONE        0
#define MAX_DIR     8

const struct{
    int d_row,d_col;
} adj[MAX_DIR] = {{-2,1},{-2,-1},{-1,-2},{-1,2},{2,1},{2,-1},{1,-2},{1,2}};

typedef pair<int,int>   Pos;    // first:row,second:col

int n,m,i,j,grid[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     bfs(void)
{
    queue<Pos>  pos_q;

    grid[1][1] = 1;
    pos_q.push(make_pair(1,1));

    for(;!pos_q.empty();pos_q.pop())
    {
        int current_row,current_col;

        current_row = pos_q.front().first;
        current_col = pos_q.front().second;

        if( current_row==j && current_col==i )
        {
            return  grid[current_row][current_col]-1;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row,adj_col;

            adj_row = current_row+adj[d].d_row;
            adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,m) || !IN_RANGE(1,adj_col,n) 
                || grid[adj_row][adj_col]!=NONE )
            {
                continue;
            }

            pos_q.push(make_pair(adj_row,adj_col));
            grid[adj_row][adj_col] = grid[current_row][current_col]+1;
        }
    }

    return  -1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ret;

    cin>>n>>m>>i>>j;
    ret = bfs();

    if( ret == -1 )
    {
        cout<<"NEVAR\n";
    }
    else
    {
        cout<<ret<<'\n';
    }
    
    return  0;
}