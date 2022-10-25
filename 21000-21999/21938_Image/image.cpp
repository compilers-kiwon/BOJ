#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIR     4

int     N,M,T,pixel[MAX_SIZE][MAX_SIZE];
bool    image[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            int R,G,B;

            cin>>R>>G>>B;
            pixel[row][col] = R+G+B;
        }
    }

    cin>>T;
}

void    build_image(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            image[row][col] = (pixel[row][col]>=3*T);
        }
    }
}

void    dfs(int row,int col)
{
    image[row][col] = false;

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
        {
            continue;
        }

        if( image[adj_row][adj_col] == true )
        {
            dfs(adj_row,adj_col);
        }
    }
}

int     get_num_of_objects(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            if( image[row][col] == true )
            {
                ret++;
                dfs(row,col);
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    build_image();

    cout<<get_num_of_objects()<<'\n';

    return  0;
}