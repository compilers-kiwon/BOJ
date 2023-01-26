#include    <iostream>

using namespace std;

#define MAX_ROW 5
#define MAX_COL 9
#define MAX_DIR 4

#define EMPTY   '.'
#define PIN     'o'
#define BLOCK   '#'

char    grid[MAX_ROW+1][MAX_COL+2];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define is_pin(r,c)         (grid[(r)][(c)]==PIN)

#define is_right_cell(r,c,s) \
    (IN_RANGE(1,(r),MAX_ROW)&&IN_RANGE(1,(c),MAX_COL)&&grid[(r)][(c)]==(s))

#define jump(from_row,from_col,mid_row,mid_col,to_row,to_col) \
    (grid[(mid_row)][(mid_col)]=EMPTY,\
        swap(grid[(from_row)][(from_col)],grid[(to_row)][to_col]))

#define restore(from_row,from_col,mid_row,mid_col,to_row,to_col) \
    (grid[(mid_row)][(mid_col)]=PIN,\
        swap(grid[(from_row)][(from_col)],grid[(to_row)][to_col]))

int     input(void)
{
    int ret = 0;

    for(int row=1;row<=MAX_ROW;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=MAX_COL;col++)
        {
            ret += (is_pin(row,col)?1:0);
        }
    }

    return  ret;
}

void    simulate(int num_of_moves,int& max_moves)
{
    for(int row=1;row<=MAX_ROW;row++)
    {
        for(int col=1;col<=MAX_COL;col++)
        {
            if( grid[row][col] != PIN )
            {
                continue;
            }

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = row+adj[d].d_row;
                int adj_col = col+adj[d].d_col;

                if( !is_right_cell(adj_row,adj_col,PIN) )
                {
                    continue;
                }

                int jump_row = adj_row+adj[d].d_row;
                int jump_col = adj_col+adj[d].d_col;

                if( !is_right_cell(jump_row,jump_col,EMPTY) )
                {
                    continue;
                }

                jump(row,col,adj_row,adj_col,jump_row,jump_col);
                simulate(num_of_moves+1,max_moves);
                restore(row,col,adj_row,adj_col,jump_row,jump_col);
                
            }
        }
    }

    max_moves = max(max_moves,num_of_moves);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int num_of_pins,num_of_removals;

        num_of_pins = input();
        num_of_removals = 0;

        simulate(0,num_of_removals);
        cout<<num_of_pins-num_of_removals<<' '<<num_of_removals<<'\n';
    }

    return  0;
}