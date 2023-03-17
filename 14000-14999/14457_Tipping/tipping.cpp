#include    <iostream>

using namespace std;

#define MAX_SIZE    (10+1)

static int  N;
static char grid[MAX_SIZE][MAX_SIZE+1];

#define toggle(c)   (((c)=='1')?'0':'1')

int tipping(int row,int col)
{
    for(int r=row;r>=1;r--)
    {
        for(int c=col;c>=1;c--)
        {
            grid[r][c] = toggle(grid[r][c]);
        }
    }

    return  0;
}

int input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int simulate(void)
{
    int ret = 0;

    for(int row=N;row>=1;row--)
    {
        for(int col=N;col>=1;col--)
        {
            if( grid[row][col] != '0' )
            {
                tipping(row,col);
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}