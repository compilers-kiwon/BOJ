#include    <iostream>
#include    <vector>
#include    <limits.h>

using namespace std;

#define NUM_OF_BLOCKS   5
#define SIZE_OF_BLOCK   4
#define MAX_SIZE        (100+1)

#define INF 0x7FFFFFFF

typedef pair<int,int>   Pos;    // first:d_row,second:d_col

const static vector<vector<Pos>> block[NUM_OF_BLOCKS] = {
    {
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}}
    },
    { 
        {{0,0},{0,1},{1,1},{1,2}},
        {{0,1},{1,0},{1,1},{2,0}}
    },
    {
        {{0,0},{0,1},{0,2},{1,2}},
        {{0,1},{1,1},{2,1},{2,0}},
        {{0,0},{1,0},{1,1},{1,2}},
        {{0,0},{0,1},{1,0},{2,0}}
    },
    {
        {{0,0},{0,1},{0,2},{1,1}},
        {{0,1},{1,0},{1,1},{2,1}},
        {{0,1},{1,0},{1,1},{1,2}},
        {{0,0},{1,0},{1,1},{2,0}}
    },
    {
        {{0,0},{0,1},{1,0},{1,1}}
    }
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

static int  N,grid[MAX_SIZE][MAX_SIZE];

#define get_adj_row(row,b,r,p)  ((row)+block[(b)][(r)][(p)].first)
#define get_adj_col(col,b,r,p)  ((col)+block[(b)][(r)][(p)].second)

int get_sum(int row,int col,
        int block_idx,int num_of_rotations)
{
    int ret = 0;

    for(int i=0;i<SIZE_OF_BLOCK;i++)
    {
        int adj_row = get_adj_row(row,block_idx,num_of_rotations,i);
        int adj_col = get_adj_col(col,block_idx,num_of_rotations,i);

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            ret = INF;
            break;
        }

        ret += grid[adj_row][adj_col];
    }

    return  ret;
}

int input(void)
{
    cin>>N;

    if( N == 0 )
    {
        return  0;
    }

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
        }
    }

    return  N;
}

int simulate(void)
{
    int ret = INT_MIN;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            for(int b=0;b<NUM_OF_BLOCKS;b++)
            {
                for(int r=0;r<block[b].size();r++)
                {
                    int sum = get_sum(row,col,b,r);

                    ret = (sum!=INF)?max(ret,sum):ret;
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

    for(int n=1;;n++)
    {
        if( input() == 0 )
        {
            break;
        }

        cout<<n<<". "<<simulate()<<'\n';
    }

    return  0;
}