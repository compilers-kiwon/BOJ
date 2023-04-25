#include    <iostream>

using namespace std;

#define MAX_SIZE    (20+1)
#define MAX_NUMBER  9
#define NONE        -1

const static int mirror[MAX_NUMBER+1] = 
        {0,1,5,NONE,NONE,2,NONE,NONE,8,NONE};

static int  N,arr[MAX_SIZE][MAX_SIZE];

#define reflect(n)  (((n)==NONE)?'?':(char)((n)+'0'))

int input(void)
{
    char    dir;

    cin>>dir>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>arr[row][col];
        }
    }

    return  dir;
}

int simulate(char dir)
{
    switch(dir)
    {
        case    'L':
        case    'R':
            for(int row=1;row<=N;row++)
            {
                for(int h_col=1,t_col=N;h_col<t_col;h_col++,t_col--)
                {
                    swap(arr[row][h_col],arr[row][t_col]);
                }
            }
            break;
        case    'U':
        case    'D':
            for(int col=1;col<=N;col++)
            {
                for(int h_row=1,t_row=N;h_row<t_row;h_row++,t_row--)
                {
                    swap(arr[h_row][col],arr[t_row][col]);
                }
            }
            break;
        deafult:
            // do nothing
            break;
    }

    return  0;
}

int print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            int num = mirror[arr[row][col]];

            cout<<reflect(num)<<((col==N)?'\n':' ');
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char    dir_to_rotate = input();

    simulate(dir_to_rotate);
    print();

    return  0;
}