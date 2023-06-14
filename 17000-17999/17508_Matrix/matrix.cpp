#include    <iostream>

using namespace std;

#define MAX_SIZE    (500+1)
#define IMPOSSIBLE  -1

#define get_symmetry_pos(pos,size)  ((size)-(pos)+1)

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE];

int is_symmetric(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            int sym_row = get_symmetry_pos(row,N);
            int sym_col = get_symmetry_pos(col,M);

            char    c1 = grid[row][col];
            char    c2 = grid[sym_row][sym_col];

            if( row==sym_row && col==sym_col && c1!='8' )
            {
                return  IMPOSSIBLE;
            }

            switch(c1)
            {
                case    '6':
                case    '9':
                    if(c2=='8' || c2=='7') return IMPOSSIBLE;
                    ret += (c1!=c2)?0:1;
                    break;
                case    '8':
                    if(c2!='8') return IMPOSSIBLE;
                    break;
                case    '7':
                    if(c2!='7') return IMPOSSIBLE;
                    ret++;
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }

    return  ret/2;
}

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<is_symmetric()<<'\n';

    return  0;
}