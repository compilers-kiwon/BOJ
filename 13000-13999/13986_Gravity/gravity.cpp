#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)

static int  n,m;
static char grid[MAX_SIZE][MAX_SIZE+1];

#define APPLE   'o'
#define EMPTY   '.'

int input(void)
{
    cin>>n>>m;

    for(int row=1;row<=n;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int fall(int row,int col)
{
    for(int down;;row=down)
    {
        down = row+1;

        if( down>n || grid[down][col]!=EMPTY )
        {
            break;
        }

        swap(grid[row][col],grid[down][col]);
    }

    return  0;
}

int simulate(void)
{
    for(int col=1;col<=m;col++)
    {
        for(int row=n;row>=1;row--)
        {
            if( grid[row][col] == APPLE )
            {
                fall(row,col);
            }
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    for(int row=1;row<=n;row++)
    {
        cout<<&grid[row][1]<<'\n';
    }

    return  0;
}