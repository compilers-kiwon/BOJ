#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    500
#define MAX_DIR     4
#define INF         0x7FFFFFFF

#define SAFE    0
#define DNAGER  1
#define DEATH   2

typedef pair<int,int>   Pos;    //fisrt:row,second:col

int     grid[MAX_SIZE+1][MAX_SIZE+1];
int     dp[MAX_SIZE+1][MAX_SIZE+1];
bool    is_queued[MAX_SIZE+1][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    mark_as(int r1,int c1,int r2,int c2,int attr)
{
    for(int row=min(r1,r2);row<=max(r1,r2);row++)
    {
        for(int col=min(c1,c2);col<=max(c1,c2);col++)
        {
            grid[row][col] = max(grid[row][col],attr);
        }
    }
}

void    read_danger(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int X1,Y1,X2,Y2;

        cin>>X1>>Y1>>X2>>Y2;
        mark_as(X1,Y1,X2,Y2,DNAGER);
    }
}

void    read_death(void)
{
    int M;

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int X1,Y1,X2,Y2;

        cin>>X1>>Y1>>X2>>Y2;
        mark_as(X1,Y1,X2,Y2,DEATH);
    }
}

void    input(void)
{
    read_danger();
    read_death();
}

int     bfs(void)
{
    int         ret;
    queue<Pos>  q;

    dp[0][0] = 0;
    q.push(make_pair(0,0));
    is_queued[0][0] = true;

    for(ret=INF;!q.empty();)
    {
        int current_row = q.front().first;
        int current_col = q.front().second;
        int current_step = dp[current_row][current_col];

        q.pop();
        is_queued[current_row][current_col] = false;

        if( current_row==MAX_SIZE && current_col==MAX_SIZE )
        {
            ret = min(ret,current_step);
            continue;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(0,adj_row,MAX_SIZE) || !IN_RANGE(0,adj_col,MAX_SIZE) )
            {
                continue;
            }

            if( grid[adj_row][adj_col]==DEATH || 
                    current_step+grid[adj_row][adj_col]>=dp[adj_row][adj_col] )
            {
                continue;
            }

            dp[adj_row][adj_col] = current_step+grid[adj_row][adj_col];
            
            if( is_queued[adj_row][adj_col] == false )
            {
                q.push(make_pair(adj_row,adj_col));
                is_queued[adj_row][adj_col] = true;
            }
        }
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=0;row<=MAX_SIZE;row++)
    {
        fill(&dp[row][0],&dp[row][MAX_SIZE+1],INF);
    }

    cout<<bfs()<<'\n';

    return  0;
}