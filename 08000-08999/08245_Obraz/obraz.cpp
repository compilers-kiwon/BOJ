#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int     n,m;
char    grid[MAX_SIZE][MAX_SIZE+1];

void    input(void)
{
    cin>>n>>m;

    for(int row=1;row<=n;row++)
    {
        cin>>&grid[row][1];
    }
}

void    print_clockwise(void)
{
    for(int col=1;col<=m;col++)
    {
        for(int row=n;row>=1;row--)
        {
            cout<<grid[row][col];
        }

        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    print_clockwise();

    return  0;
}