#include    <iostream>

using namespace std;

#define MAX_SIZE    (750+1)

#define RIGHT   0
#define DOWN    1
#define LEFT    2
#define UP      3
#define MAX_DIR 4

#define NEXT_DIR(d) (((d)+1)%MAX_DIR)

static int  N,square[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IN_AREA(r,c,size) \
    (IN_RANGE(1,(r),(size))&&IN_RANGE(1,(c),(size)))

#define is_empty(n) ((n)==0)

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

int walk(void)
{
    int row,col,d;

    row = col = 1;
    d = RIGHT;

    for(int i=1;i<=N*N;i++)
    {
        square[row][col] = i;

        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_AREA(adj_row,adj_col,N) 
                || !is_empty(square[adj_row][adj_col]) )
        {
            d = NEXT_DIR(d);
            adj_row = row+adj[d].d_row;
            adj_col = col+adj[d].d_col;
        }

        row = adj_row;
        col = adj_col;
    }

    return  0;
}

int print_square(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cout<<square[row][col]<<((col==N)?'\n':' ');
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    walk();
    print_square();

    return  0;
}