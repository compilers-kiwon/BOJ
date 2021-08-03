#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define NONE        -1

#define WALL    'W'
#define EMPTY   '.'
#define START   'S'

int     N,M,step[MAX_SIZE][MAX_SIZE];
int     s_row,s_col;
char    grid[MAX_SIZE][MAX_SIZE+1];
bool    visitable[MAX_SIZE][MAX_SIZE],caught;

#define is_empty(c)     ((c)==EMPTY)
#define is_convey(c)    ((c)=='L'||(c)=='R'||(c)=='U'||(c)=='D')
#define is_camera(c)    ((c)=='C')

typedef pair<int,int>   Pos;    // first:row,second:col

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR]={{-1,0},{1,0},{0,-1},{0,1}};

#define get_convey_dir(c)   ((c)=='L'?LEFT:(c)=='R'?RIGHT:(c)=='U'?UP:DOWN)

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == START )
            {
                s_row = row;
                s_col = col;
            }

            step[row][col] = NONE;
        }
    }
}

void    mark_visitable(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            if( is_empty(c) || is_convey(c) )
            {
                visitable[row][col] = true;
            }
        }
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            if( is_camera(c) == true )
            {
                for(int d=UP;d<=RIGHT;d++)
                {
                    for(int offset=1;;offset++)
                    {
                        int adj_row = row+adj[d].d_row*offset;
                        int adj_col = col+adj[d].d_col*offset;

                        if( grid[adj_row][adj_col] == WALL )
                        {
                            break;
                        }

                        if( grid[adj_row][adj_col] == START )
                        {
                            caught = true;
                            return;
                        }

                        if( grid[adj_row][adj_col] == EMPTY )
                        {
                            visitable[adj_row][adj_col] = false;
                        }
                    }
                }
            }
        }
    }
}

void    simulate(void)
{
    queue<Pos>  pos_q;

    for(pos_q.push(make_pair(s_row,s_col)),step[s_row][s_col]=0;!pos_q.empty();pos_q.pop())
    {
        int current_row = pos_q.front().first;
        int current_col = pos_q.front().second;

        if( is_convey(grid[current_row][current_col]) == true )
        {
            int adj_row = current_row+adj[get_convey_dir(grid[current_row][current_col])].d_row;
            int adj_col = current_col+adj[get_convey_dir(grid[current_row][current_col])].d_col;

            if( visitable[adj_row][adj_col]==true &&
                (step[adj_row][adj_col]==NONE||step[current_row][current_col]<step[adj_row][adj_col]) )
            {
                pos_q.push(make_pair(adj_row,adj_col));
                step[adj_row][adj_col] = step[current_row][current_col];
            }

            continue;
        }

        for(int d=UP;d<=RIGHT;d++)
        {
            int adj_row,adj_col;

            adj_row = current_row+adj[d].d_row;
            adj_col = current_col+adj[d].d_col;

            if( visitable[adj_row][adj_col]==true
                && (step[adj_row][adj_col]==NONE||step[current_row][current_col]+1<step[adj_row][adj_col]) )
            {
                pos_q.push(make_pair(adj_row,adj_col));
                step[adj_row][adj_col] = step[current_row][current_col]+1;
            }
        }
    }
}

void    print_steps(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == EMPTY )
            {
                cout<<step[row][col]<<'\n';
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    mark_visitable();

    if( caught == false )
    {
        simulate();
    }
    
    print_steps();

    return  0;
}