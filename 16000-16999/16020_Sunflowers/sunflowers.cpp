#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define INF         0x7FFFFFFF

int N,record[MAX_SIZE+1][MAX_SIZE+1];

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

#define TOP_LEFT        0
#define TOP_RIGHT       1
#define BOTTOM_LEFT     2
#define BOTTOM_RIGHT    3

#define MAX_DIR 4

const struct{
    int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

const struct{
    int adj_flower,adj_growth;
} taller[MAX_DIR] = {{DOWN,RIGHT},{LEFT,DOWN},{RIGHT,UP},{UP,LEFT}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     read_record(int row,int col)
{
    int ret;

    if( !IN_RANGE(1,row,N) || !IN_RANGE(1,col,N) )
    {
        ret = INF;
    }
    else
    {
        ret = record[row][col];
    }

    return  ret;
}

bool    check_record(int rotate_dir)
{
    bool    ret = true;

    for(int row=1;row<=N&&ret!=false;row++)
    {
        for(int col=1;col<=N&&ret!=false;col++)
        {
            int adj_flower_row,adj_flower_col;
            int adj_growth_row,adj_growth_col;

            adj_flower_row = row+adj[taller[rotate_dir].adj_flower].d_row;
            adj_flower_col = col+adj[taller[rotate_dir].adj_flower].d_col;

            adj_growth_row = row+adj[taller[rotate_dir].adj_growth].d_row;
            adj_growth_col = col+adj[taller[rotate_dir].adj_growth].d_col;

            if( record[row][col]>=read_record(adj_flower_row,adj_flower_col)
                || record[row][col]>=read_record(adj_growth_row,adj_growth_col) )
            {
                ret = false;
            }
        }
    }

    return  ret;
}

void    print_rotated_record(int rotate_dir)
{
    switch(rotate_dir)
    {
        case    TOP_LEFT:
            for(int row=1;row<=N;row++)
            {
                for(int col=1;col<=N;col++)
                {
                    cout<<record[row][col];

                    if( col != N )
                    {
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
            break;
        case    TOP_RIGHT:
            for(int col=N;col>=1;col--)
            {
                for(int row=1;row<=N;row++)
                {
                    cout<<record[row][col];

                    if( row != N )
                    {
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
            break;
        case    BOTTOM_LEFT:
            for(int col=1;col<=N;col++)
            {
                for(int row=N;row>=1;row--)
                {
                    cout<<record[row][col];

                    if( row != 1 )
                    {
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
            break;
        case    BOTTOM_RIGHT:
            for(int row=N;row>=1;row--)
            {
                for(int col=N;col>=1;col--)
                {
                    cout<<record[row][col];

                    if( col != 1 )
                    {
                        cout<<' ';
                    }
                }
                cout<<'\n';
            }
            break;
        default : 
            // do nothing
            break;
    }
}

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>record[row][col];
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int d=0;d<MAX_DIR;d++)
    {
        if( check_record(d) == true )
        {
            print_rotated_record(d);
            break;
        }
    }

    return  0;
}