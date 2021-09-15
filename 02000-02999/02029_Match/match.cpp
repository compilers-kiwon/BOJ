#include    <iostream>

using namespace std;

#define MAX_SIZE        10
#define TYPE_OF_SQUARE  3
#define EMPTY           ' '

const int   size_of_square[TYPE_OF_SQUARE] = {10,7,4};
const char  original[MAX_SIZE][MAX_SIZE+1] =
{
    "+--+--+--+",
    "|..|..|..|",
    "|..|..|..|",
    "+--+--+--+",
    "|..|..|..|",
    "|..|..|..|",
    "+--+--+--+",
    "|..|..|..|",
    "|..|..|..|",
    "+--+--+--+"
};

const char  square[TYPE_OF_SQUARE][MAX_SIZE][MAX_SIZE+1] =
{
    {
        "+--+--+--+",
        "|        |",
        "|        |",
        "+        +",
        "|        |",
        "|        |",
        "+        +",
        "|        |",
        "|        |",
        "+--+--+--+"
    },
    {
        "+--+--+",
        "|     |",
        "|     |",
        "+     +",
        "|     |",
        "|     |",
        "+--+--+"
    },
    {
        "+--+",
        "|  |",
        "|  |",
        "+--+"
    }
};

char    grid[MAX_SIZE][MAX_SIZE+1];

int     get_num_of_removed_match(void)
{
    int cnt = 0;

    for(int row=0;row<MAX_SIZE;row++)
    {
        for(int col=0;col<MAX_SIZE;col++)
        {
            if( grid[row][col] != original[row][col] )
            {
                cnt++;
            }
        }
    }

    return  (cnt/2);
}

bool    compare_square(int row,int col,int type)
{
    for(int r=0;r<size_of_square[type];r++)
    {
        for(int c=0;c<size_of_square[type];c++)
        {
            if( square[type][r][c]!=EMPTY && grid[row+r][col+c]!=square[type][r][c] )
            {
                return  false;
            }
        }
    }

    return  true;
}

int     find_sqaure(void)
{
    int ret = 0;

    for(int t=0;t<TYPE_OF_SQUARE;t++)
    {
        int size = size_of_square[t];

        for(int row=0;row<=MAX_SIZE-size;row++)
        {
            for(int col=0;col<=MAX_SIZE-size;col++)
            {
                if( compare_square(row,col,t) == true )
                {
                    ret++;
                }
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int row=0;row<MAX_SIZE;row++)
    {
        cin>>&grid[row][0];
    }

    cout<<get_num_of_removed_match()<<' '<<find_sqaure()<<'\n';

    return  0;
}