#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (8+1)
#define MAX_DIR     4

#define MIN_BONUS_POINT 10

static int  N,K,grid[MAX_SIZE][MAX_SIZE];
static vector<int>  bullet;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_bonus_target(t)  ((t)>=MIN_BONUS_POINT)
#define shoot_target(t,b)   (max((t)-(b),0))
#define get_new_target(t)   ((t)/4)
#define is_empty(cell)      ((cell).first==0)

int input(void)
{
    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
        }
    }

    for(int i=1;i<=K;i++)
    {
        int b;

        cin>>b;
        bullet.push_back(b);
    }

    return  0;
}

int copy_grid(int src[][MAX_SIZE],
            pair<int,int> dst[][MAX_SIZE])
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            dst[row][col] = {src[row][col],src[row][col]};
        }
    }

    return  0;
}

int place_new_target(int row,int col,
            int p,pair<int,int> g[][MAX_SIZE])
{
    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        if( is_empty(g[adj_row][adj_col]) )
        {
            g[adj_row][adj_col] = {p,p};
        }
    }
    return  0;
}

int simulate(const vector<int>& shoot_pos)
{
    int             ret = 0;
    pair<int,int>   cur_grid[MAX_SIZE][MAX_SIZE];

    copy_grid(grid,cur_grid);

    for(int i=0;i<K;i++)
    {
        int row = shoot_pos[i];

        for(int col=1;col<=N;col++)
        {
            int&    cur_point = cur_grid[row][col].first;
            int&    init_point = cur_grid[row][col].second;

            if (cur_point==0) continue;

            if (is_bonus_target(cur_point))
            {
                ret += init_point;
                cur_point = 0;
            }
            else
            {
                cur_point = shoot_target(cur_point,bullet[i]);

                if( cur_point == 0 )
                {
                    int new_target = get_new_target(init_point);

                    ret += init_point;

                    if( new_target > 0 )
                    {
                        place_new_target(row,col,new_target,cur_grid);
                    }
                }
            }
            break;
        }
    }

    return  ret;
}

int dfs(vector<int>& shoot_pos,int& max_point)
{
    if( shoot_pos.size() == K )
    {
        max_point = max(max_point,simulate(shoot_pos));
        return  0;
    }

    for(int row=1;row<=N;row++)
    {
        shoot_pos.push_back(row);
        dfs(shoot_pos,max_point);
        shoot_pos.pop_back();
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_point;
    vector<int> shoot_pos;

    input();
    max_point = 0;

    dfs(shoot_pos,max_point);
    cout<<max_point<<'\n';

    return  0;
}