#include    <iostream>

using namespace std;

#define MAX_SIZE    (10+1)
#define MAX_OP      (250+1)

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

#define get_dir(c)          ((c)=='U'?UP:(c)=='D'?DOWN:(c)=='L'?LEFT:RIGHT)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int     N;
char    grid[MAX_SIZE][MAX_SIZE+1],operation[MAX_OP+1];

#define EMPTY   '.'
#define HORI    '-'
#define VIRT    '|'
#define CROSS   '+'

void    input(void)
{
    cin>>N>>&operation[1];

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            grid[row][col] = EMPTY;
        }
    }
}

void    print_on_grid(int row,int col,int dir)
{
    char    mark;
    char&   current=grid[row][col];

    if( dir==UP || dir==DOWN )
    {
        mark = VIRT;
    }
    else
    {
        mark = HORI;
    }

    if( current == EMPTY )
    {
        current = mark;
    }
    else if( current==mark || current==CROSS )
    {
        // do nothing
    }
    else
    {
        current = CROSS;
    }
}

void    simulate(void)
{
    int row,col,i;

    for(i=row=col=1;operation[i];i++)
    {
        int adj_row,adj_col;
        int d = get_dir(operation[i]);
        
        adj_row = row+adj[d].d_row;
        adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        // current
        print_on_grid(row,col,d);

        // adj
        print_on_grid(adj_row,adj_col,d);

        row = adj_row;
        col = adj_col;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    for(int row=1;row<=N;row++)
    {
        cout<<&grid[row][1]<<'\n';
    }

    return  0;
}