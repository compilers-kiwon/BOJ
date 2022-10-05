#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (30+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;    // first:row,second:col

int N,M;
int origin[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>origin[row][col];
        }
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>result[row][col];
        }
    }
}

void    bfs(int row,int col,int grid[MAX_SIZE][MAX_SIZE],
                bool visited[MAX_SIZE][MAX_SIZE],vector<Pos>& group)
{
    queue<Pos>  q;

    visited[row][col] = true;
    q.push(make_pair(row,col));

    for(;!q.empty();q.pop())
    {
        group.push_back(q.front());

        int current_row = q.front().first;
        int current_col = q.front().second;
        int current_idx = grid[current_row][current_col];

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
            {
                continue;
            }

            if( visited[adj_row][adj_col]==true ||
                    grid[adj_row][adj_col]!=current_idx )
            {
                continue;
            }

            visited[adj_row][adj_col] = true;
            q.push(make_pair(adj_row,adj_col));
        }
    }
}

void    get_groups(int grid[MAX_SIZE][MAX_SIZE],vector<vector<Pos>>& g)
{
    bool    visited[MAX_SIZE][MAX_SIZE];

    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][M+1],false);
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( visited[row][col] == false )
            {
                vector<Pos> group;

                bfs(row,col,grid,visited,group);
                g.push_back(group);
            }
        }
    }
}

void    vaccinate(int grid[MAX_SIZE][MAX_SIZE],vector<Pos>& p,int v)
{
    for(int i=0;i<p.size();i++)
    {
        int&    row = p[i].first;
        int&    col = p[i].second;

        grid[row][col] = v;
    }
}

void    restore(int grid[MAX_SIZE][MAX_SIZE],vector<Pos>& p,int v)
{
    vaccinate(grid,p,v);
}

bool    compare_grids(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( origin[row][col] != result[row][col] )
            {
                return  false;
            }
        }
    }

    return  true;
}

bool    simulate(vector<vector<Pos>>& groups)
{
    for(int i=0;i<groups.size();i++)
    {
        vector<Pos>&    g = groups[i];
        
        int&    row = g.front().first;
        int&    col = g.front().second;
        int     v = 0;

        if( origin[row][col] != result[row][col] )
        {
            v = origin[row][col];
            vaccinate(origin,g,result[row][col]);
        }

        if( compare_grids() == true )
        {
            return  true;
        }

        if( v != 0 )
        {
            restore(origin,g,v);
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<vector<Pos>> origin_groups;

    input();
    get_groups(origin,origin_groups);

    if( simulate(origin_groups) == true )
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return  0;
}