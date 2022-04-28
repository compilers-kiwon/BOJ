#include    <iostream>

using namespace std;

#define MAX_STATE               6
#define MOVE_TO_NEXT_STATE(s)   (((s)+1)%MAX_STATE)

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define MAX_SIZE    1000

int grid[MAX_SIZE][MAX_SIZE];

#define move(row,col,dir)   ((row)+=adj[(dir)].d_row,(col)+=adj[(dir)].d_col)

bool    is_empty_cell(int row,int col,int dir)
{
    int adj_row = row+adj[dir].d_row;
    int adj_col = col+adj[dir].d_col;

    return  (grid[adj_row][adj_col]==0);
}

void    init(void)
{
    int current,row,col,state;

    row = col = current = 1;
    state = 0;

    for(int i=1;i<=999*999;i++)
    {
        grid[row][col] = i;

        switch(state)
        {
            case    0:
                move(row,col,RIGHT);
                state = MOVE_TO_NEXT_STATE(state);
                break;
            case    1:
                if( is_empty_cell(row,col,LEFT) == true )
                {
                    i--;
                    state = MOVE_TO_NEXT_STATE(state);
                }
                else
                {
                    move(row,col,DOWN);
                }
                break;
            case    2:
                if( col == 1 )
                {
                    i--;
                    state = MOVE_TO_NEXT_STATE(state);
                }
                else
                {
                    move(row,col,LEFT);
                }
                break;
            case    3:
                move(row,col,DOWN);
                state = MOVE_TO_NEXT_STATE(state);
                break;
            case    4:
                if( is_empty_cell(row,col,UP) == true )
                {
                    i--;
                    state = MOVE_TO_NEXT_STATE(state);
                }
                else
                {
                    move(row,col,RIGHT);
                }
                break;
            case    5:
                if( row == 1 )
                {
                    i--;
                    state = MOVE_TO_NEXT_STATE(state);
                }
                else
                {
                    move(row,col,UP);
                }
                break;
            default:
                // do nothing
                break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for(;;)
    {
        int N;

        cin>>N;

        if( N == 0 )
        {
            break;
        }

        cout<<N<<" => "<<grid[N][N]<<'\n';
    }

    return  0;
}