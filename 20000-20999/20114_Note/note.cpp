#include    <iostream>
#include    <string>

using namespace std;

#define MAX_ROW_SIZE    (10+1)
#define MAX_COL_SIZE    (100*10+1)
#define UNKNOWN         '?'

int     N,H,W;
char    note[MAX_ROW_SIZE][MAX_COL_SIZE+1];

void    input(void)
{
    cin>>N>>H>>W;

    for(int row=1;row<=H;row++)
    {
        cin>>&note[row][1];
    }
}

char    check_grid(int s_col)
{
    for(int row=1;row<=H;row++)
    {
        for(int col=s_col;col<s_col+W;col++)
        {
            if( note[row][col] != UNKNOWN )
            {
                return  note[row][col];
            }
        }
    }

    return  UNKNOWN;
}

void    recover(string& result)
{
    for(int col=1;result.length()!=N;col+=W)
    {
        result.push_back(check_grid(col));
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  src;

    input();
    recover(src);

    cout<<src<<'\n';

    return  0;
}