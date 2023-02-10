#include    <iostream>
#include    <string>

using namespace std;

#define MAX_ROW 5
#define MAX_COL (100000/5)

#define ROW_SIZE    5
#define COL_SIZE    3

#define TRUE    1
#define FALSE   0

static int  N;
static char grid[MAX_ROW][MAX_COL+COL_SIZE];

const string digits = "0123456789";

const char  number[10][5][3] = {
    {{'#','#','#'},{'#','.','#'},{'#','.','#'},{'#','.','#'},{'#','#','#'}},
    {{'#','.',' '},{'#','.',' '},{'#','.',' '},{'#','.',' '},{'#','.',' '}},
    {{'#','#','#'},{'.','.','#'},{'#','#','#'},{'#','.','.'},{'#','#','#'}},
    {{'#','#','#'},{'.','.','#'},{'#','#','#'},{'.','.','#'},{'#','#','#'}},
    {{'#','.','#'},{'#','.','#'},{'#','#','#'},{'.','.','#'},{'.','.','#'}},
    {{'#','#','#'},{'#','.','.'},{'#','#','#'},{'.','.','#'},{'#','#','#'}},
    {{'#','#','#'},{'#','.','.'},{'#','#','#'},{'#','.','#'},{'#','#','#'}},
    {{'#','#','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'}},
    {{'#','#','#'},{'#','.','#'},{'#','#','#'},{'#','.','#'},{'#','#','#'}},
    {{'#','#','#'},{'#','.','#'},{'#','#','#'},{' ','.','#'},{'#','#','#'}},
};

const int next_offset[10] = {2,0,2,2,2,2,2,2,2,2};

#define char2int(c) ((int)((c)-'0'))

int input(void)
{
    string  str;
    int     ptr;

    cin>>N>>str;
    ptr = 0;

    for(int row=0;row<MAX_ROW;row++)
    {
        for(int col=0;col<N/MAX_ROW;col++)
        {
            grid[row][col] = str[ptr++];
        }

        for(int col=N/MAX_ROW;col<N/MAX_ROW+2;col++)
        {
            grid[row][col] = '.';
        }
    }

    return  0;
}

int compare_number(int row,int col,int num)
{
    for(int r=0;r<ROW_SIZE;r++)
    {
        for(int c=0;c<COL_SIZE;c++)
        {
            if( number[num][r][c] == ' ' )
            {
                continue;
            }

            if( number[num][r][c] != grid[row+r][col+c] )
            {
                return  FALSE;
            }
        }
    }

    return  TRUE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  found;

    input();

    for(int col=0;col<N/MAX_ROW;col++)
    {
        if( grid[0][col] == '.' )
        {
            continue;
        }

        for(int i=0;i<=9;i++)
        {
            if( compare_number(0,col,i) == TRUE )
            {
                found.push_back(digits[i]);
                break;
            }
        }

        col += next_offset[char2int(found.back())];
    }

    cout<<found<<'\n';

    return  0;
}