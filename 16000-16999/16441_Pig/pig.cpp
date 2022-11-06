#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4

typedef struct{int r,c,d;}  Wolf;

int     N,M;
bool    visited[MAX_SIZE][MAX_SIZE][MAX_DIR];
char    grid[MAX_SIZE][MAX_SIZE+1];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void    input(queue<Wolf>& q)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == 'W' )
            {
                for(int d=0;d<MAX_DIR;d++)
                {
                    Wolf    w = {row,col,d};

                    q.push(w);
                    visited[row][col][d] = true;
                }
            }
        }
    }
}

void    move_wolf(int row,int col,int dir,queue<Wolf>& q)
{
    Wolf    w = {row,col,dir};

    q.push(w);
    visited[row][col][dir] = true;
}

void    simulate(queue<Wolf>& q)
{
    for(;!q.empty();q.pop())
    {
        int current_row = q.front().r;
        int current_col = q.front().c;
        int current_dir = q.front().d;
        
        int adj_row = current_row+adj[current_dir].d_col;
        int adj_col = current_col+adj[current_dir].d_row;

        switch(grid[adj_row][adj_col])
        {
            case    '.':
                for(int d=0;d<MAX_DIR;d++)
                {
                    if( visited[adj_row][adj_col][d] == false )
                    {
                        move_wolf(adj_row,adj_col,d,q);
                    }
                }
                break;
            case    '+':
                move_wolf(adj_row,adj_col,current_dir,q);
                break;
            case    '#':
                if( grid[current_row][current_col] == '+' )
                {
                    for(int d=0;d<MAX_DIR;d++)
                    {
                        if( visited[current_row][current_col][d] == false )
                        {
                            move_wolf(current_row,current_col,d,q);
                        }
                    }
                }
                break;
            case    'W':
            default:
                // do nothing
                break;
        }
    }
}

bool    is_safe(int row,int col)
{
    bool    ret = true;

    for(int d=0;d<MAX_DIR;d++)
    {
        if( visited[row][col][d] == true )
        {
            ret = false;
            break;
        }
    }

    return  ret;
}

void    print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            if( c=='.' && is_safe(row,col)==true )
            {
                c = 'P';
            }

            cout<<c;
        }

        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Wolf> q;

    input(q);
    simulate(q);
    print();

    return  0;
}