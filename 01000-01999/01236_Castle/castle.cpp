#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    (50+1)
#define NONE        0

int         N,M;
bool        defensible[MAX_SIZE][MAX_SIZE];
set<int>    defensed_row,defensed_col;

#define place_guard(row,col) \
    {defensible[(row)][(col)]=false;\
        defensed_row.insert((row));defensed_col.insert((col));}

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        char    buf[MAX_SIZE+1];

        cin>>&buf[1];

        for(int col=1;col<=M;col++)
        {
            switch(buf[col])
            {
                case    'X':
                    place_guard(row,col);
                    break;
                case    '.':
                    defensible[row][col] = true;
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }
}

int     simulate(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( defensible[row][col] == false )
            {
                continue;
            }

            if( defensed_row.find(row) == defensed_row.end()
                    && defensed_col.find(col) == defensed_col.end() )
            {
                ret++;
                place_guard(row,col);
            }
        }
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( defensible[row][col] == false )
            {
                continue;
            }

            if( defensed_row.find(row) == defensed_row.end()
                    || defensed_col.find(col) == defensed_col.end() )
            {
                ret++;
                place_guard(row,col);
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
    cout<<simulate()<<'\n';

    return  0;
}