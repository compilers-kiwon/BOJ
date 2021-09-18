#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define INF         0x7FFFFFFF
#define TBD         -1
#define MOD(n)      ((n)%1000000)

#define EMPTY   '.'
#define CRATER  '*'
#define TARGET  'X'
#define NORTH   'N'
#define EAST    'E'
#define SOUTH   'S'
#define WEST    'W'

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3
#define MAX_DIR 4

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define TURN_LEFT(curr)     (((curr)+(MAX_DIR-1))%MAX_DIR)
#define TURN_RIGHT(curr)    (((curr)+1)%MAX_DIR)
#define PREV_DIR(curr)      (((curr)+2)%MAX_DIR)

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<Pos,int>   Robot;

int     N,M;
int     dp[MAX_SIZE][MAX_SIZE][MAX_DIR];
int     path[MAX_SIZE][MAX_SIZE][MAX_DIR];
Pos     target;
char    grid[MAX_SIZE][MAX_SIZE+1];
Robot   start;

int     get_dir(char c)
{
    int ret;

    switch(c)
    {
        case    NORTH:
            ret = UP;
            break;
        case    EAST:
            ret = RIGHT;
            break;
        case    SOUTH:
            ret = DOWN;
            break;
        case    WEST:
            ret = LEFT;
            break;
        default:
            ret = MAX_DIR;
            break;
    }

    return  ret;
}

bool    input(void)
{
    cin>>N>>M;

    if( N==0 && M==0 )
    {
        return  false;
    }

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            if( IN_RANGE('A',c,'Z') == true )
            {
                int d = get_dir(c);

                if( d == MAX_DIR )
                {
                    target = make_pair(row,col);
                }
                else
                {
                    start.first = make_pair(row,col);
                    start.second = d;
                }
            }

            for(int d=UP;d<MAX_DIR;d++)
            {
                dp[row][col][d] = INF;
                path[row][col][d] = 0;
            }
        }
    }

    return  true;
}

void    move(Pos curr,int curr_dir,Pos next,int next_dir,queue<Robot>& q)
{
    int&    curr_step = dp[curr.first][curr.second][curr_dir];
    int&    next_step = dp[next.first][next.second][next_dir];

    int&    curr_path = path[curr.first][curr.second][curr_dir];
    int&    next_path = path[next.first][next.second][next_dir];

    if( curr_step+1 <= next_step )
    {
        if( curr_step+1 == next_step )
        {
            next_path = MOD(next_path+curr_path);
        }
        else
        {
            next_path = curr_path;
            q.push(make_pair(next,next_dir));
        }

        next_step = curr_step+1;
    }
}

int     find_shortest_path(void)
{
    int             ret;
    queue<Robot>    q;

    q.push(start);

    dp[start.first.first][start.first.second][start.second] = 0;
    path[start.first.first][start.first.second][start.second] = 1;

    for(ret=INF;!q.empty();)
    {
        bool    arrived = false;

        for(int i=1,size=q.size();i<=size;i++,q.pop())
        {
            Robot   current = q.front();
            
            Pos curr_pos = current.first;
            int curr_dir = current.second;
                        
            if( grid[curr_pos.first][curr_pos.second] == TARGET )
            {
                arrived = true;
                ret = dp[curr_pos.first][curr_pos.second][curr_dir];
                continue;
            }

            // 1.TURN LEFT
            move(curr_pos,curr_dir,curr_pos,TURN_LEFT(curr_dir),q);

            // 2.TURN RIGHT
            move(curr_pos,curr_dir,curr_pos,TURN_RIGHT(curr_dir),q);

            // 3.FORWAD X
            for(int X=1;;X++)
            {
                int adj_row = curr_pos.first+adj[curr_dir].d_row*X;
                int adj_col = curr_pos.second+adj[curr_dir].d_col*X;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M)
                    || grid[adj_row][adj_col]==CRATER )
                {
                    break;
                }

                move(curr_pos,curr_dir,make_pair(adj_row,adj_col),curr_dir,q);
            }
        }

        if( arrived == true )
        {
            break;
        }
    }

    return  ((ret==INF)?0:ret);
}

int     main(void)
{
    for(;;)
    {
        if( input() == false )
        {
            break;
        }

        int shortest_path = find_shortest_path();

        if( shortest_path == 0 )
        {
            cout<<"0 0\n";
            continue;
        }

        int cnt = 0;

        for(int d=UP;d<MAX_DIR;d++)
        {
            if( dp[target.first][target.second][d] == shortest_path )
            {
                cnt = MOD(cnt+path[target.first][target.second][d]);
            }
        }

        cout<<shortest_path<<' '<<cnt<<'\n';
    }

    return  0;
}