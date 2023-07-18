#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

#define YELLOW  0
#define RED     1

static int  N,M,grid[MAX_SIZE][MAX_SIZE];

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++) cin>>grid[row][0];
    for(int col=1;col<=M;col++) cin>>grid[0][col];

    return  0;
}

int simulate(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            grid[row][col] =
                (grid[row][col-1]==grid[row-1][col])?YELLOW:RED;
        }
    }

    return  grid[N][M];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}