#include    <iostream>

using namespace std;

#define MAX_SIZE    300
#define UNKNOWN     -1

int H,W,X,Y;
int A[MAX_SIZE+1][MAX_SIZE+1];
int B[MAX_SIZE*2+1][MAX_SIZE*2+1];

#define IN_RANGE(MIN,n,MAX)     ((MIN)<=(n)&&(n)<=(MAX))
#define GET_SEPARATOR(pos,size) ((pos)==(size)?'\n':' ')

void    input(void)
{
    cin>>H>>W>>X>>Y;

    for(int row=1;row<=H;row++)
    {
        fill(&A[row][1],&A[row][W+1],UNKNOWN);
    }

    for(int row=1;row<=H+X;row++)
    {
        for(int col=1;col<=W+Y;col++)
        {
            cin>>B[row][col];

            if( (IN_RANGE(1,row,H)&&IN_RANGE(1,col,W)) &&
                    !(IN_RANGE(1+X,row,H+X)&&IN_RANGE(1+Y,col,W+Y)) )
            {
                A[row][col] = B[row][col];
            }
        }
    }
}

void    restore(void)
{
    for(int row=1;row<=H;row++)
    {
        for(int col=1;col<=W;col++)
        {
            if( A[row][col] == UNKNOWN )
            {
                A[row][col] = B[row][col]-A[row-X][col-Y];
            }
        }
    }
}

void    print_arr(void)
{
    for(int row=1;row<=H;row++)
    {
        for(int col=1;col<=W;col++)
        {
            cout<<A[row][col]<<GET_SEPARATOR(col,W);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    restore();
    print_arr();

    return  0;
}