#include    <iostream>

using namespace std;

#define MAX_SIZE    10

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,K;
    char    grid[MAX_SIZE][MAX_SIZE];

    cin>>N>>K;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            cin>>grid[row][col];
        }
    }

    for(int row=0;row<N*K;row++)
    {
        for(int col=0;col<N*K;col++)
        {
            cout<<grid[row/K][col/K]<<' ';
        }

        cout<<'\n';
    }

    return  0;
}