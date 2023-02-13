#include    <iostream>

using namespace std;

#define MAX_SIZE    (20+1)
#define CHAR        '*'

static int  N;
static char grid[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int print(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cout<<((grid[row][col]!=CHAR)?' ':CHAR);
        }

        cout<<'\n';
    }

    return  0;
}

int mark_char(int s_row,int s_col,int d_row,int d_col)
{
    for(int row=s_row,col=s_col;IN_RANGE(1,row,N)
            &&IN_RANGE(1,col,N);row+=d_row,col+=d_col)
    {
        grid[row][col] = CHAR;
    }

    return  0;
}

int draw(void)
{
    mark_char(1,1,0,1);
    mark_char(1,1,1,0);
    mark_char(1,N,1,-1);

    mark_char(N,N,0,-1);
    mark_char(N,N,-1,0);
    mark_char(N,N,-1,-1);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    draw();print();

    return  0;
}