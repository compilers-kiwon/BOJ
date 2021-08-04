#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (100+1)

int     N;
char    grid[MAX_SIZE][MAX_SIZE+1];
string  row_str[MAX_SIZE],col_str[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }
}

void    get_row_str(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            row_str[row].push_back(grid[row][col]);
        }
    }
}

void    get_col_str(void)
{
    for(int col=1;col<=N;col++)
    {
        for(int row=1;row<=N;row++)
        {
            col_str[col].push_back(grid[row][col]);
        }
    }
}

bool    is_magic_square(void)
{
    for(int pos=1;pos<=N;pos++)
    {
        if( row_str[pos] != col_str[pos] )
        {
            return  false;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_row_str();
    get_col_str();

    if( is_magic_square() == true )
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return  0;
}