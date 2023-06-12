#include    <iostream>
#include    <queue>
#include    <vector>
#include    <cstring>

using namespace std;

#define MAX_SIZE        100
#define MAX_DIR         4
#define NUM_OF_PLAYERS  3
#define INF             (MAX_SIZE*MAX_SIZE)

static int  h,w;
static int  dp[MAX_SIZE+2][MAX_SIZE+2][NUM_OF_PLAYERS];
static char grid[MAX_SIZE+2][MAX_SIZE+2];

typedef pair<int,int>   Pos;

const static struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_player(c)    ((c)=='$')
#define is_door(c)      ((c)=='#')
#define is_wall(c)      ((c)=='*')
#define is_empty(c)     ((c)=='.')

int get_sum(int row,int col)
{
    int ret = 0;

    for(int i=0;i<NUM_OF_PLAYERS;i++)
    {
        ret += dp[row][col][i];
    }

    return  ret;
}

int escape(int row,int col,int idx)
{
    queue<Pos>  q;

    q.push({row,col});
    dp[row][col][idx] = 0;

    for(;!q.empty();q.pop())
    {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        int cur_dp = dp[cur_row][cur_col][idx];

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = cur_row+adj[d].d_row;
            int adj_col = cur_col+adj[d].d_col;

            if( !IN_RANGE(0,adj_row,h+1) || !IN_RANGE(0,adj_col,w+1) )
            {
                continue;
            }

            if( is_wall(grid[adj_row][adj_col]) )
            {
                continue;
            }

            int adj_dp = cur_dp+
                    (is_door(grid[adj_row][adj_col])?1:0);

            if( adj_dp < dp[adj_row][adj_col][idx] )
            {
                q.push({adj_row,adj_col});
                dp[adj_row][adj_col][idx] = adj_dp;
            }
        }
    }

    return  0;
}

int input(vector<Pos>& p)
{
    cin>>h>>w;

    fill(&grid[0][0],&grid[0][w+2],'.');
    fill(&grid[h+1][0],&grid[h+1][w+2],'.');

    for(int row=1;row<=h;row++)
    {
        cin>>&grid[row][1];
        grid[row][0] = grid[row][w+1] = '.';

        for(int col=1;col<=w;col++)
        {
            if( is_player(grid[row][col]) )
            {
                grid[row][col] = '.';
                p.push_back({row,col});
            }
        }
    }

    return  0;
}

int simulate(const vector<Pos>& p)
{
    memset(&dp[0][0][0],INF,sizeof(dp));

    for(int i=0;i<p.size();i++)
    {
        escape(p[i].first,p[i].second,i);
    }

    int ret = INF;

    for(int row=0;row<=h+1;row++)
    {
        for(int col=0;col<=w+1;col++)
        {
            ret = min(ret,
                      get_sum(row,col)-(is_door(grid[row][col])?2:0));
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        vector<Pos> p = {{0,0}};

        input(p);
        cout<<simulate(p)<<'\n';
    }

    return  0;
}