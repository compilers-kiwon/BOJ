#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef pair<int,int>   Pos;    // first:row,second:col

#define MAX_ROW (100+1)
#define MAX_COL 10
#define MAX_DIR 4

#define EMPTY   '0'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     N,K;
char    grid[MAX_ROW][MAX_COL+2];
bool    visited[MAX_ROW][MAX_COL+1];

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void    input(void)
{
    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }
}

void    init_visited(void)
{
    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][MAX_COL+1],false);
    }
}

void    fall_down(int col)
{
    int empty_ptr,haybale_ptr;

    for(empty_ptr=haybale_ptr=N;empty_ptr>=1&&haybale_ptr>=1;empty_ptr--)
    {
        if( grid[empty_ptr][col] != EMPTY )
        {
            continue;
        }

        for(haybale_ptr=empty_ptr-1;haybale_ptr>=1&&grid[haybale_ptr][col]==EMPTY;haybale_ptr--);

        if( haybale_ptr >= 1 )
        {
            swap(grid[empty_ptr][col],grid[haybale_ptr][col]);
        }
    }
}

void    get_adj_cells(int row,int col,vector<Pos>& cells)
{
    queue<Pos>   q;

    visited[row][col] = true;
    q.push(make_pair(row,col));
    cells.push_back(make_pair(row,col));

    for(;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,MAX_COL) )
            {
                continue;
            }

            if( visited[adj_row][adj_col]==true || 
                    grid[adj_row][adj_col]!=grid[current_row][current_col] )
            {
                continue;
            }

            visited[adj_row][adj_col] = true;
            q.push(make_pair(adj_row,adj_col));
            cells.push_back(make_pair(adj_row,adj_col));
        }
    }
}

void    remove_cells(vector<Pos>& cells)
{
    for(int i=0;i<cells.size();i++)
    {
        int&    row = cells[i].first;
        int&    col = cells[i].second;

        grid[row][col] = EMPTY;
    }
}

bool    disappear(void)
{
    bool    ret;

    ret = false;
    init_visited();

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=MAX_COL;col++)
        {
            if( grid[row][col]!=EMPTY && visited[row][col]==false )
            {
                vector<Pos> adj_cells;

                get_adj_cells(row,col,adj_cells);

                if( adj_cells.size() >= K )
                {
                    remove_cells(adj_cells);
                    ret = true;
                }
            }
        }
    }

    return  ret;
}

void    simulate(void)
{
    for(;;)
    {
        bool    updated = disappear();

        if( updated == true )
        {
            for(int col=1;col<=MAX_COL;col++)
            {
                fall_down(col);
            }
        }
        else
        {
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    for(int row=1;row<=N;row++)
    {
        cout<<&grid[row][1]<<'\n';
    }

    return  0;
}