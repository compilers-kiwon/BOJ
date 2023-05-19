#include    <iostream>

using namespace std;

#define MAX_SIZE    8
#define QUEEN       '*'

static struct{int row,col;} pos[MAX_SIZE];
static char grid[MAX_SIZE][MAX_SIZE+1];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IN_AREA(row,col) \
    (IN_RANGE(0,(row),MAX_SIZE-1)&&IN_RANGE(0,(col),MAX_SIZE-1))

#define TRUE    1
#define FALSE   0

int move(int q,int d_row,int d_col)
{
    if( d_row==0 && d_col==0 )
    {
        return  TRUE;
    }

    int&    row = pos[q].row;
    int&    col = pos[q].col;

    for(int offset=1;;offset++)
    {
        int adj_row = row+d_row*offset;
        int adj_col = col+d_col*offset;

        if( !IN_AREA(adj_row,adj_col) )
        {
            break;
        }

        if( grid[adj_row][adj_col] == QUEEN )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int simulate(void)
{
    for(int q_idx=0;q_idx<MAX_SIZE;q_idx++)
    {
        for(int d_row=-1;d_row<=1;d_row++)
        {
            for(int d_col=-1;d_col<=1;d_col++)
            {
                if( move(q_idx,d_row,d_col) == FALSE )
                {
                    return  FALSE;
                }
            }
        }
    }

    return  TRUE;
}

int input(void)
{
    int ptr = 0;

    for(int row=0;row<MAX_SIZE;row++)
    {
        cin>>&grid[row][0];

        for(int col=0;col<MAX_SIZE;col++)
        {
            if( grid[row][col] == QUEEN )
            {
                pos[ptr++] = {row,col};
            }
        }
    }

    return  ptr;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout<<(input()==MAX_SIZE &&
            simulate()?"valid":"invalid")<<'\n';

    return  0;
}