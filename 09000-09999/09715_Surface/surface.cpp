#include    <iostream>
#include    <cstring>

using namespace std;

#define MAX_SIZE    (50+1)
#define MAX_DIR     4

static int  R,C,grid[MAX_SIZE+1][MAX_SIZE+1];

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int input(void)
{
    memset(grid,0,sizeof(grid));
    scanf("%d %d",&R,&C);

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            scanf("%1d",&grid[row][col]);
        }
    }

    return  0;
}

int get_num_of_visible_surface(int row,int col)
{
    if( grid[row][col] == 0 )
    {
        return  0;
    }

    int ret = 2;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        ret += max(0,grid[row][col]-grid[adj_row][adj_col]);
    }

    return  ret;
}

int count_surface_area(void)
{
    int ret = 0;

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            ret += get_num_of_visible_surface(row,col);
        }
    }

    return  ret;
}

int main(void)
{
    int T;

    scanf("%d",&T);

    for(int t=1;t<=T;t++)
    {
        input();
        printf("%d\n",count_surface_area());
    }

    return  0;
}