#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10+1)
#define NOT_VISITED -1

#define KNIGHT      0
#define BISHOP      1
#define ROOK        2
#define MAX_PIECES  3

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define get_adj_target(t,n) ((t)+(((t)==(n))?1:0))

typedef pair<int,int>           Pos;    // first:row,second:col
typedef struct{int p,r,c,t;}    State;  // p:piece,r:row,c:col,t:target

int N,grid[MAX_SIZE][MAX_SIZE];
int dp[MAX_PIECES][MAX_SIZE][MAX_SIZE][MAX_SIZE*MAX_SIZE];

Pos     input(void)
{
    Pos ret;

    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];

            if( grid[row][col] == 1 )
            {
                ret = make_pair(row,col);
            }
        }
    }

    for(int p=KNIGHT;p<=ROOK;p++)
    {
        for(int row=1;row<=N;row++)
        {
            for(int col=1;col<=N;col++)
            {
                fill(&dp[p][row][col][1],&dp[p][row][col][N*N+1],NOT_VISITED);
            }
        }
    }

    return  ret;
}

void    move_knight(int row,int col,vector<Pos>& p)
{
    static const struct{int d_row,d_col;} adj[8] =
        {{-1,-2},{-2,-1},{-2,1},{-1,2},
                    {1,2},{2,1},{2,-1},{1,-2}};

    for(int i=0;i<8;i++)
    {
        int adj_row = row+adj[i].d_row;
        int adj_col = col+adj[i].d_col;

        if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
        {
            p.push_back(make_pair(adj_row,adj_col));
        }
    }    
}

void    move_bishop(int row,int col,vector<Pos>& p)
{
    static const struct{int d_row,d_col;}
            adj[4] = {{-1,-1},{-1,1},{1,1},{1,-1}};

    for(int i=0;i<4;i++)
    {
        for(int offset=1;;offset++)
        {
            int adj_row = row+adj[i].d_row*offset;
            int adj_col = col+adj[i].d_col*offset;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
            {
                break;
            }

            p.push_back(make_pair(adj_row,adj_col));
        }
    }
}

void    move_rook(int row,int col,vector<Pos>& p)
{
    static const struct{int d_row,d_col;}
            adj[4] = {{-1,0},{1,0},{0,-1},{0,1}};

    for(int i=0;i<4;i++)
    {
        for(int offset=1;;offset++)
        {
            int adj_row = row+adj[i].d_row*offset;
            int adj_col = col+adj[i].d_col*offset;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
            {
                break;
            }

            p.push_back(make_pair(adj_row,adj_col));
        }
    }    
}

void    move(int piece,int row,
                int col,vector<Pos>& p)
{
    switch(piece)
    {
        case    KNIGHT:
            move_knight(row,col,p);
            break;
        case    BISHOP:
            move_bishop(row,col,p);
            break;
        case    ROOK:
            move_rook(row,col,p);
            break;
        default:
            // do nothing
            break;
    }
}

int     simulate(int row,int col)
{
    int             ret;
    queue<State>    q;

    for(int i=KNIGHT;i<=ROOK;i++)
    {
        State   s = {i,row,col,2};
        
        q.push(s);
        dp[i][row][col][2] = 0;
    }

    for(;!q.empty();q.pop())
    {
        int current_piece = q.front().p;
        int current_row = q.front().r;
        int current_col = q.front().c;
        int current_target = q.front().t;
        
        int current_num = grid[current_row][current_col];
        int current_step = dp[current_piece][current_row][current_col][current_target];

        if( current_target==N*N && current_num==N*N )
        {
            ret = current_step;
            break;
        }

        vector<Pos> adj_pos;

        move(current_piece,current_row,current_col,adj_pos);

        for(int i=0;i<adj_pos.size();i++)
        {
            int&    adj_row = adj_pos[i].first;
            int&    adj_col = adj_pos[i].second;
            int     adj_target = get_adj_target(current_target,current_num);

            if( dp[current_piece][adj_row][adj_col][adj_target] != NOT_VISITED )
            {
                continue;
            }

            State   s = {current_piece,adj_row,adj_col,adj_target};

            q.push(s);
            dp[current_piece][adj_row][adj_col][adj_target] = current_step+1;
        }

        for(int adj_piece=KNIGHT;adj_piece<=ROOK;adj_piece++)
        {
            if( adj_piece == current_piece )
            {
                continue;
            }

            if( dp[adj_piece][current_row][current_col][current_target] != NOT_VISITED )
            {
                continue;
            }

            State   s = {adj_piece,current_row,current_col,current_target};
            
            q.push(s);
            dp[adj_piece][current_row][current_col][current_target] = current_step+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos init;

    init = input();
    cout<<simulate(init.first,init.second)<<'\n';

    return  0;
}