#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (20+1)
#define MAX_DIR     4

#define EMPTY   0
#define ME      1
#define ENEMY   2

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    //first:row,second:col

int     N,M,grid[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

vector<Pos>         empty_pos;
vector<vector<Pos>> group;

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];

            if( grid[row][col] == EMPTY )
            {
                empty_pos.push_back(make_pair(row,col));
            }
        }
    }
}

void    find_group(int row,int col,vector<Pos>& g)
{
    visited[row][col] = true;
    g.push_back(make_pair(row,col));

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        if( grid[adj_row][adj_col]!=ENEMY || visited[adj_row][adj_col]!=false )
        {
            continue;
        }

        find_group(adj_row,adj_col,g);
    }
}

bool    is_locked_up(vector<Pos>& g)
{
    for(int i=0;i<g.size();i++)
    {
        int&    row = g[i].first;
        int&    col = g[i].second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = row+adj[d].d_row;
            int adj_col = col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
            {
                continue;
            }

            if( grid[adj_row][adj_col] == EMPTY )
            {
                return  false;
            }
        }
    }

    return  true;
}

int     get_max_num_of_enemy_to_be_defeated(void)
{
    int ret = 0;

    for(int i=0;i<empty_pos.size()-1;i++)
    {
        grid[empty_pos[i].first][empty_pos[i].second] = ME;

        for(int j=i+1;j<empty_pos.size();j++)
        {
            int tmp = 0;

            grid[empty_pos[j].first][empty_pos[j].second] = ME;
            
            for(int k=0;k<group.size();k++)
            {
                if( is_locked_up(group[k]) == true )
                {
                    tmp += group[k].size();
                }
            }

            ret = max(ret,tmp);

            grid[empty_pos[j].first][empty_pos[j].second] = EMPTY;
        }

        grid[empty_pos[i].first][empty_pos[i].second] = EMPTY;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col]==ENEMY && visited[row][col]==false )
            {
                vector<Pos> g;

                find_group(row,col,g);
                group.push_back(g);
            }
        }
    }

    cout<<get_max_num_of_enemy_to_be_defeated()<<'\n';

    return  0;
}