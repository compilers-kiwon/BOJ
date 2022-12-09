#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (500+1)
#define MAX_DIR     4
#define INF         0x7FFFFFFF

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define char2int(c)         ((int)((c)-'0'))

#define ROCK    -1
#define HOLE    -2
#define EXIT    -3

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<Pos,int>   State;  // first:Pos,second:time

int H,W,grid[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

#define row first
#define col second

Pos     input(void)
{
    Pos ret;

    cin>>W>>H;

    for(int row=1;row<=H;row++)
    {
        char    buf[MAX_SIZE+1];

        cin>>&buf[1];

        for(int col=1;col<=W;col++)
        {
            int&    n = grid[row][col];

            switch(buf[col])
            {
                case 'E':n=EXIT;break;
                case 'R':n=ROCK;break;
                case 'H':n=HOLE;break;
                case 'T':n=0,ret=make_pair(row,col);break;
                default :n=char2int(buf[col]);break;
            }

            dp[row][col] = INF;
        }
    }

    return  ret;
}

bool    move(int dir,Pos& src,Pos& dst,int& t)
{
    int&    row = dst.row;
    int&    col = dst.col;

    t = 0;

    for(int offset=1;;offset++)
    {
        row = src.row+adj[dir].d_row*offset;
        col = src.col+adj[dir].d_col*offset;

        if( !IN_RANGE(1,row,H) || !IN_RANGE(1,col,W) || grid[row][col]==HOLE )
        {
            return false;
        }

        if( grid[row][col]==EXIT || grid[row][col]==ROCK )
        {
            if( grid[row][col] == ROCK )
            {
                row -= adj[dir].d_row;
                col -= adj[dir].d_col;
            }

            return  true;
        }

        t += grid[row][col];
    }

    return  false;
}

int     simulate(Pos& start)
{
    int             ret;
    queue<State>    q;

    q.push(make_pair(start,0));
    dp[start.row][start.col] = 0;

    for(ret=INF;!q.empty();q.pop())
    {
        Pos current_pos = q.front().first;
        int current_time = q.front().second;

        if( grid[current_pos.row][current_pos.col] == EXIT )
        {
            ret = min(ret,current_time);
            continue;
        }

        if( current_time > dp[current_pos.row][current_pos.col] )
        {
            continue;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            Pos next_pos;
            int time;

            if( move(d,current_pos,next_pos,time) == true &&
                        current_time+time < dp[next_pos.row][next_pos.col] )
            {
                q.push(make_pair(next_pos,current_time+time));
                dp[next_pos.row][next_pos.col] = current_time+time;
            }
        }
    }

    return  ((ret==INF)?-1:ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos t = input();

    cout<<simulate(t)<<'\n';

    return  0;
}