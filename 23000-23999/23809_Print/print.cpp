#include    <iostream>

using namespace std;

#define MAX_CELL_SIZE   100
#define MAX_BOX_SIZE    5
#define MAX_SIZE        (MAX_CELL_SIZE*MAX_BOX_SIZE)

static char grid[MAX_SIZE+1][MAX_SIZE+1];

int init_box(int cell_size)
{
    int box_size = cell_size*MAX_BOX_SIZE;

    for(int row=0;row<box_size;row++)
    {
        fill(&grid[row][0],&grid[row][box_size],' ');
    }

    return  0;
}

int fill_char(int cell_row,int cell_col,
                    int cell_size,char end)
{
    int row = cell_row*cell_size;
    int col = cell_col*cell_size;

    for(int r=0;r<cell_size;r++)
    {
        for(int c=0;c<cell_size;c++)
        {
            grid[row+r][col+c] = '@';
        }

        grid[row+r][col+cell_size] = end;
    }

    return  0;
}

int print_box(int cell_size)
{
    int row_size = cell_size*MAX_BOX_SIZE;

    for(int row=0;row<row_size;row++)
    {
        cout<<&grid[row][0]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    init_box(N);

    fill_char(0,0,N,' ');fill_char(0,4,N,'\0');                     // @   @
    fill_char(1,0,N,' ');fill_char(1,3,N,'\0');                     // @  @
    fill_char(2,0,N,' ');fill_char(2,1,N,' ');fill_char(2,2,N,'\0');// @@@
    fill_char(3,0,N,' ');fill_char(3,3,N,'\0');                     // @  @
    fill_char(4,0,N,' ');fill_char(4,4,N,'\0');                     // @   @

    print_box(N);

    return  0;
}