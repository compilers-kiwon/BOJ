#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4
#define INF         0x7FFFFFFF
#define NONE        -1

typedef pair<int,int>   Pos;    // first:row,second:col

int     M,N,grid[MAX_SIZE][MAX_SIZE];
int     num_of_connected,color_map[MAX_SIZE][MAX_SIZE];
bool    counted[MAX_SIZE][MAX_SIZE];

vector<Pos> group[MAX_SIZE*MAX_SIZE];
vector<int> connected[MAX_SIZE*MAX_SIZE];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>M>>N;

    for(int row=1;row<=M;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
        }
    }
}

void    dfs(int row,int col,vector<Pos>& g)
{
    if( counted[row][col] == true )
    {
        return;
    }

    counted[row][col] = true;
    g.push_back(make_pair(row,col));

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        if( grid[row][col] != grid[adj_row][adj_col] )
        {
            continue;
        }

        dfs(adj_row,adj_col,g);
    }
}

void    find_group(void)
{
    for(int row=1;row<=M;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( counted[row][col] == false )
            {
                num_of_connected++;
                dfs(row,col,group[num_of_connected]);
            }
        }
    }
}

void    mark_group(void)
{
    for(int i=1;i<=num_of_connected;i++)
    {
        for(int j=0;j<group[i].size();j++)
        {
            int&    row = group[i][j].first;
            int&    col = group[i][j].second;

            color_map[row][col] = i;
        }
    }
}

void    get_connected(void)
{
    for(int i=1;i<=num_of_connected;i++)
    {
        vector<bool>    visited(num_of_connected+1,false);

        visited[i] = true;

        for(int j=0;j<group[i].size();j++)
        {
            int&    row = group[i][j].first;
            int&    col = group[i][j].second;

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = row+adj[d].d_row;
                int adj_col = col+adj[d].d_col;

                if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
                {
                    continue;
                }

                if( visited[color_map[adj_row][adj_col]] == false )
                {
                    visited[color_map[adj_row][adj_col]] = true;
                    connected[i].push_back(color_map[adj_row][adj_col]);
                }
            } 
        }
    }
}

int     get_max_distance(int s)
{
    int         ret;
    queue<int>  q;
    vector<int> visited(num_of_connected+1,-1);

    q.push(s);
    visited[s] = 0;

    for(ret=NONE;!q.empty();q.pop())
    {
        int current = q.front();

        ret = max(ret,visited[current]);

        for(int j=0;j<connected[current].size();j++)
        {
            int adj = connected[current][j];

            if( visited[adj] == NONE )
            {
                q.push(adj);
                visited[adj] = visited[current]+1;
            }
        }
    }

    return  ret;
}

int     get_min_distance(void)
{
    int ret = INF;

    for(int i=1;i<=num_of_connected;i++)
    {
        ret = min(ret,get_max_distance(i));
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    find_group();
    mark_group();

    get_connected();
    cout<<get_min_distance()<<'\n';

    return  0;
}