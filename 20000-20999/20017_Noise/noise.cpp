#include    <iostream>

using namespace std;

#define MAX_SIZE    (20+1)

int n,m,a,arr[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>n>>m>>a;

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=m;col++)
        {
            cin>>arr[row][col];
        }
    }
}

int     get_penalty(void)
{
    int ret = 0;

    for(int row=2;row<=n;row++)
    {
        for(int col=1;col<=m;col++)
        {
            if( arr[row][col] > 2*arr[row-1][col] )
            {
                ret += a;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_penalty()<<'\n';

    return  0;
}