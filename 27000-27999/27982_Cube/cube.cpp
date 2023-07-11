#include    <iostream>
#include    <cstring>

using namespace std;

#define MAX_SIZE    5
#define NUM_OF_FULL_CUBES   6

enum {
    X_AXIS = 0,
    Y_AXIS = 1,
    Z_AXIS = 2,
    MAX_AXIS = 3
};

static int  N,M;
static bool is_filled[MAX_SIZE+2][MAX_SIZE+2][MAX_SIZE+2];

int get_num_of_adj_cubes(int pos[])
{
    int ret = 0;

    for(int i=0;i<MAX_AXIS;i++)
    {
        for(int offset=-1;offset<=1;offset+=2)
        {
            int adj[MAX_AXIS];

            memcpy(adj,pos,sizeof(adj));
            adj[i] += offset;

            int&    x = adj[X_AXIS];
            int&    y = adj[Y_AXIS];
            int&    z = adj[Z_AXIS];

            ret += is_filled[x][y][z]?1:0;
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N>>M;

    for(int m=1;m<=M;m++)
    {
        int i,j,k;

        cin>>i>>j>>k;
        is_filled[i][j][k] = true;
    }

    return  0;
}

int simulate(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                int pos[MAX_AXIS] = {i,j,k};

                if( is_filled[i][j][k] &&
                        get_num_of_adj_cubes(pos)==NUM_OF_FULL_CUBES )
                {
                    ret++;
                }
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}