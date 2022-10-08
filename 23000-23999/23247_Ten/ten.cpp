#include    <iostream>

using namespace std;

#define MAX_SIZE                (300+1)
#define GET_LENGTH(start,end)   ((end)-(start)+1)

int n,m,grid[MAX_SIZE][MAX_SIZE],sum_in_row[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>n>>m;

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=m;col++)
        {
            cin>>grid[row][col];
            sum_in_row[row][col] = sum_in_row[row][col-1]+grid[row][col];
        }
    }
}

bool    is_ten(int r1,int c1,int r2,int c2)
{
    int sum = 0;

    for(int row=r1;row<=r2;row++)
    {
        sum += sum_in_row[row][c2]-sum_in_row[row][c1-1];
    }

    return  (sum==10);
}

int     get_num_of_ten(int s_row,int s_col)
{
    int ret = 0;

    for(int e_row=s_row;e_row<=min(n,(s_row+10)-1);e_row++)
    {
        for(int e_col=s_col;e_col<=m;e_col++)
        {
            int h = GET_LENGTH(s_row,e_row);
            int w = GET_LENGTH(s_col,e_col);

            if( grid[s_row][s_col]+(h*w-1) > 10 )
            {
                break;
            }

            if( is_ten(s_row,s_col,e_row,e_col) == true )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     count_ten(void)
{
    int ret = 0;

    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=m;col++)
        {
            ret += get_num_of_ten(row,col);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<count_ten()<<'\n';

    return  0;
}