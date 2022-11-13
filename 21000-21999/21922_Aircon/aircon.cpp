#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (2000+1)

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

#define EMPTY       0
#define AIRCON      9
#define MAX_WALL    5

int     N,M,grid[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE][MAX_DIR];

typedef struct{int d,r,c;}  State;

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

/*
    ( ) (|) (-) (/) (\)
=======================
U |  U   U   D   R   L
D |  D   D   U   L   R
L |  L   R   L   D   U
R |  R   L   R   U   D
*/
const int   dir_table[MAX_DIR][MAX_WALL] =
    {{UP,UP,DOWN,RIGHT,LEFT},{DOWN,DOWN,UP,LEFT,RIGHT},
     {LEFT,RIGHT,LEFT,DOWN,UP},{RIGHT,LEFT,RIGHT,UP,DOWN}};

void    push_q(queue<State>& q,int row,int col)
{
    for(int d=UP;d<=RIGHT;d++)
    {
        State   s = {d,row,col};

        q.push(s);
        visited[row][col][d] = true;
    }
}

void    input(queue<State>& q)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];

            if( grid[row][col] == AIRCON )
            {
                push_q(q,row,col);
                grid[row][col] = EMPTY;
            }
        }
    }
}

int     get_num_of_cool(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( visited[row][col][UP]==true || visited[row][col][DOWN]==true ||
                    visited[row][col][LEFT]==true || visited[row][col][RIGHT]==true )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     simulate(queue<State>& q)
{
    for(;!q.empty();q.pop())
    {
        int current_dir = q.front().d;
        int current_row = q.front().r;
        int current_col = q.front().c;

        int adj_row = current_row+adj[current_dir].d_row;
        int adj_col = current_col+adj[current_dir].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        int adj_dir = dir_table[current_dir][grid[adj_row][adj_col]];

        if( visited[adj_row][adj_col][adj_dir] == true )
        {
            continue;
        }

        State   s = {adj_dir,adj_row,adj_col};

        q.push(s);
        visited[adj_row][adj_col][adj_dir] = true;
    }

    return  get_num_of_cool();
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<State>    state_q;

    input(state_q);
    cout<<simulate(state_q)<<'\n';

    return  0;
}