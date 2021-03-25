#include    <iostream>

using namespace std;

#define MAX_SIZE    (2000+1)

int N,W,L,grid[MAX_SIZE][MAX_SIZE];
int cnt_of_bad_cell[MAX_SIZE][MAX_SIZE];

#define get_num_of_bad_cell(r1,c1,r2,c2)    (cnt_of_bad_cell[(r2)][(c2)]-cnt_of_bad_cell[(r1)-1][(c2)] \
                                                -cnt_of_bad_cell[(r2)][(c1)-1]+cnt_of_bad_cell[(r1)-1][(c1)-1])
void    input(int t)
{
    cin>>N>>W>>L;

    for(int i=1;i<=W;i++)
    {
        int row,col;

        cin>>row>>col;
        grid[row][col] = t;
    }
}

void    count_bad_cell(int t)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cnt_of_bad_cell[row][col] = 
                cnt_of_bad_cell[row][col-1]+cnt_of_bad_cell[row-1][col]
                -cnt_of_bad_cell[row-1][col-1]+(grid[row][col]==t?1:0);
        }
    }
}

int     find_largest_square(void)
{
    if( L == W )
    {
        return  N*N;
    }

    for(int size=N-1;size>=2;size--)
    {
        for(int row=1;row+(size-1)<=N;row++)
        {
            for(int col=1;col+(size-1)<=N;col++)
            {
                if( get_num_of_bad_cell(row,col,row+(size-1),col+(size-1)) <= L )
                {
                    return  size*size;
                }
            }
        }
    }

    return  1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Z;

    cin>>Z;

    for(int z=1;z<=Z;z++)
    {
        input(z);
        count_bad_cell(z);

        cout<<find_largest_square()<<'\n';
    }

    return  0;
}