#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>           Pos;    // first:row,second:col
typedef struct{Pos p;int d,m;}  State;  // d:direction,m:num of passed mirrors

#define DOOR    '#'
#define WALL    '*'
#define MIRROR  '!'
#define EMPTY   '.'

#define START       0
#define END         1
#define MAX_DOORS   2

#define MAX_SIZE    (50+1)
#define INF         0x7FFFFFFF

#define UP      0
#define DOWN    1
#define RIGHT   2
#define LEFT    3
#define MAX_DIR 4

#define IN_RANGE(MIN,pos,MAX)   (((MIN)<=(pos).first&&(pos).first<=(MAX)) \
                                    &&((MIN)<=(pos).second&&(pos).first<=(MAX)))

#define MAX_REFLECTIONS 2

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,1},{0,-1}};
const int   reflection[MAX_DIR][MAX_REFLECTIONS] = {{RIGHT,LEFT},{RIGHT,LEFT},{UP,DOWN},{UP,DOWN}};

Pos     door[MAX_DOORS];
int     N,dp[MAX_SIZE][MAX_SIZE][MAX_DIR];
char    grid[MAX_SIZE][MAX_SIZE+1];

void    input(void)
{
    int ptr = START;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>&grid[i][1];
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( grid[row][col] == DOOR )
            {
                door[ptr] = make_pair(row,col);
                ptr++;
            }
            
            fill(&dp[row][col][0],&dp[row][col][MAX_DIR],INF);
        }
    }
}

void    init_simulation(queue<State>& q)
{
    for(int d=UP;d<=LEFT;d++)
    {
        State   s;

        s.p = door[START];
        s.d = d;
        s.m = 0;

        q.push(s);
        dp[s.p.first][s.p.second][d] = 0;
    }
}

void    simulate(void)
{
    queue<State>    q;

    for(init_simulation(q);!q.empty();q.pop())
    {
        int current_row = q.front().p.first;
        int current_col = q.front().p.second;
        int current_dir = q.front().d;
        int current_num_of_mirrors = q.front().m;

        if( current_row==door[END].first 
                && current_col==door[END].second )
        {
            continue;
        }

        State   s;

        if( grid[current_row][current_col] == MIRROR )
        {
            s.p = make_pair(current_row,current_col);
            s.m = current_num_of_mirrors+1;

            for(int i=0;i<MAX_REFLECTIONS;i++)
            {
                s.d = reflection[current_dir][i];

                if( s.m < dp[current_row][current_col][s.d] )
                {
                    q.push(s);
                    dp[current_row][current_col][s.d] = s.m;
                }
            }
        }

        s.p.first = current_row+adj[current_dir].d_row;
        s.p.second = current_col+adj[current_dir].d_col;

        if( IN_RANGE(1,s.p,N) && grid[s.p.first][s.p.second]!=WALL 
                && current_num_of_mirrors<dp[s.p.first][s.p.second][current_dir] )
        {
            s.m = current_num_of_mirrors;
            s.d = current_dir;

            q.push(s);
            dp[s.p.first][s.p.second][current_dir] = current_num_of_mirrors;
        }        
    }
}

int     get_min_num_of_mirrors(void)
{
    int ret = INF;

    for(int i=0;i<MAX_DIR;i++)
    {
        ret = min(ret,dp[door[END].first][door[END].second][i]);
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    cout<<get_min_num_of_mirrors()<<'\n';

    return  0;
}