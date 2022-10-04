#include    <iostream>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    (1000+1)
#define NOT_VISITED 0

typedef pair<int,int>   Pos;

int N,M,grid[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int size_of_shape[MAX_SIZE*MAX_SIZE];

#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];
        }
    }
}

int     find_shape(int row,int col,int idx)
{
    int         ret;
    queue<Pos>  q;

    q.push(make_pair(row,col));
    visited[row][col] = idx;

    for(ret=0;!q.empty();q.pop(),ret++)
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
            {
                continue;
            }

            if( grid[adj_row][adj_col]==0 || visited[adj_row][adj_col]!=NOT_VISITED )
            {
                continue;
            }

            visited[adj_row][adj_col] = idx;
            q.push(make_pair(adj_row,adj_col));
        }
    }

    return  ret;
}

void    get_size_of_shape(void)
{
    int idx = 1;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col]==1 && visited[row][col]==NOT_VISITED )
            {
                size_of_shape[idx] = find_shape(row,col,idx);
                idx++;
            }
        }
    }
}

void    get_connected(int row,int col,set<int>& connected)
{
    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        if( grid[adj_row][adj_col] == 0 )
        {
            continue;
        }

        connected.insert(visited[adj_row][adj_col]);
    }
}

int     get_size_of_connected(set<int>& connected)
{
    int                 ret = 0;
    set<int>::iterator  it;

    for(it=connected.begin();it!=connected.end();it++)
    {
        ret += size_of_shape[*it];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_size;

    input();
    get_size_of_shape();

    max_size = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == 1 )
            {
                int idx = visited[row][col];

                max_size = max(max_size,size_of_shape[idx]-1);
            }
            else
            {
                set<int>    connected;

                get_connected(row,col,connected);
                max_size = max(max_size,get_size_of_connected(connected)+1);
            }
        }
    }

    cout<<max_size<<'\n';

    return  0;
}