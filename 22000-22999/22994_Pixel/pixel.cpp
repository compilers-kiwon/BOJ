#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  ni,mj;
static char grid[MAX_SIZE][MAX_SIZE+1];

int get_divisors(int n,priority_queue<int>& div)
{
    for(int i=1;i<=n/2;i++)
    {
        if( n%i == 0 )
        {
            div.push(i);
            div.push(n/i);
        }
    }

    return  0;
}

int get_gcd_in_col(priority_queue<int>& div)
{
    for(;!div.empty();div.pop())
    {
        int     len = div.top();
        bool    equal = true;

        for(int col=1;col<=mj;col++)
        {
            for(int row=1;row<=ni;row+=len)
            {
                for(int offset=1;offset<=len-1;offset++)
                {
                    if( grid[row][col] != grid[row+offset][col] )
                    {
                        equal = false;
                        break;
                    }
                }

                if( equal == false )
                {
                    break;
                }
            }

            if( equal == false )
            {
                break;
            }
        }

        if( equal == true )
        {
            return  len;
        }
    }

    return  0;
}

int get_gcd_in_row(priority_queue<int>& div)
{
    for(;!div.empty();div.pop())
    {
        int     len = div.top();
        bool    equal = true;

        for(int row=1;row<=ni;row++)
        {
            for(int col=1;col<=mj;col+=len)
            {
                for(int offset=1;offset<=len-1;offset++)
                {
                    if( grid[row][col] != grid[row][col+offset] )
                    {
                        equal = false;
                        break;
                    }
                }

                if( equal == false )
                {
                    break;
                }
            }

            if( equal == false )
            {
                break;
            }
        }

        if( equal == true )
        {
            return  len;
        }
    }
    
    return  0;
}

int print_pixel(int row_size,int col_size)
{
    cout<<ni/row_size<<' '<<mj/col_size<<'\n';

    for(int row=1;row<=ni;row+=row_size)
    {
        for(int col=1;col<=mj;col+=col_size)
        {
            cout<<grid[row][col];
        }
        cout<<'\n';
    }

    return  0;
}

int input(void)
{
    cin>>ni>>mj;

    for(int row=1;row<=ni;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int row_size,col_size;
    priority_queue<int> row_div,col_div;

    input();

    get_divisors(ni,row_div);
    get_divisors(mj,col_div);

    row_size = get_gcd_in_col(row_div);
    col_size = get_gcd_in_row(col_div);

    print_pixel(row_size,col_size);
    return  0;
}