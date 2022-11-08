#include	<iostream>
#include	<vector>
#include    <queue>

using namespace std;

#define MAX_SIZE        (100+1)
#define MAX_DIR         4
#define NUM_OF_CHASERS  3
#define NOT_VISITED     -1
#define INF             0x7FFFFFFF

#define EMPTY   '0'
#define WALL    '1'

typedef pair<int,int>   Pos;

int     R,C,visited[MAX_SIZE][MAX_SIZE][NUM_OF_CHASERS+1];
Pos     chaser[NUM_OF_CHASERS+1];
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>R>>C;

    for(int row=1;row<=R;row++)
    {
        cin>>&grid[row][1];
    }

    for(int i=1;i<=NUM_OF_CHASERS;i++)
    {
        cin>>chaser[i].first>>chaser[i].second;
    }
}

void    init_visited(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            fill(&visited[row][col][1],
                    &visited[row][col][NUM_OF_CHASERS+1],NOT_VISITED);
        }
    }
}

void    bfs(int chaser_idx)
{
    queue<Pos>  q;
    int&        row = chaser[chaser_idx].first;
    int&        col = chaser[chaser_idx].second;

    q.push(make_pair(row,col));
    visited[row][col][chaser_idx] = 0;
        
    for(;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
            {
                continue;
            }

            if( grid[adj_row][adj_col]==WALL || 
                    visited[adj_row][adj_col][chaser_idx]!=NOT_VISITED )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            visited[adj_row][adj_col][chaser_idx] = 
                    visited[current_row][current_col][chaser_idx]+1;
        }
    }
}

int     is_visitable_for_chasers(int row,int col)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_CHASERS;i++)
    {
        if( visited[row][col][i] == NOT_VISITED )
        {
            ret = INF;
            break;
        }

        ret = max(ret,visited[row][col][i]);
    }

    return  ret;
}

int     get_min_time_to_gather(int& num_of_pos)
{
    int ret = INF;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            int time = is_visitable_for_chasers(row,col);

            if( time <= ret )
            {
                if( time < ret )
                {
                    num_of_pos = 0;
                }

                ret = time;
                num_of_pos++;
            }
        }
    }

    return  ((ret==INF)?NOT_VISITED:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init_visited();

    for(int i=1;i<=NUM_OF_CHASERS;i++)
    {
        bfs(i);
    }

    int time,cnt;

    cout<<(time=get_min_time_to_gather(cnt))<<'\n';

    if( time != NOT_VISITED )
    {
        cout<<cnt<<'\n';
    }

    return  0;
}