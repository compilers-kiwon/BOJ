#include    <iostream>

using namespace std;

#define CELL_SIZE   5
#define MAX_SIZE    100

char    grid[CELL_SIZE*MAX_SIZE][CELL_SIZE*MAX_SIZE+1];

void    print_cell(int row,int col,int size)
{
    for(int r=0;r<size;r++)
    {
        for(int c=0;c<size;c++)
        {
            grid[row+r][col+c] = '@';
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int row=0;row<CELL_SIZE;row++)
    {
        for(int col=0;col<((row==0)?CELL_SIZE:1);col++)
        {
            print_cell(row*N,col*N,N);
        }
    }

    for(int row=0;row<N*CELL_SIZE;row++)
    {
        cout<<&grid[row][0]<<'\n';
    }

    return  0;
}