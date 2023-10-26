#include    <iostream>

using namespace std;

const static int MAX_SIZE = 1000+1;
const static int NUM_OF_DIRS = 3;
const static int INF = 0x7FFFFFFF;

static int N,M,grid[MAX_SIZE][MAX_SIZE];
static int dp[MAX_SIZE][MAX_SIZE][NUM_OF_DIRS+1];

static inline bool in_range(int MIN,int n,int MAX) {
    return  ((MIN)<=(n) && (n)<=(MAX));
}

void    input(void)
{
    cin>>N>>M;

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            cin>>grid[row][col];
            for (int d=1;d<=NUM_OF_DIRS;d++) {
                dp[row][col][d] = INF;
            }
        }
    }

    for (int col=1;col<=M;col++) {
        for (int d=1;d<=NUM_OF_DIRS;d++) {
            dp[1][col][d] = grid[1][col];
        }
    }
}

void    simulate(void)
{
    const int offset[NUM_OF_DIRS+1] = {0,-1,0,1};
    const int adj[NUM_OF_DIRS+1][NUM_OF_DIRS-1] = 
        {{0,0},{2,3},{1,3},{1,2}};
    
    for (int row=1;row<N;row++) {
        for (int col=1;col<=M;col++) {
            for (int d=1;d<=NUM_OF_DIRS;d++) {
                int adj_col = col+offset[d];
                if (!in_range(1,adj_col,M)) continue;

                for (int i=0;i<NUM_OF_DIRS-1;i++) {
                    dp[row+1][adj_col][adj[d][i]] = 
                        min(dp[row+1][adj_col][adj[d][i]],
                            dp[row][col][d]+grid[row+1][adj_col]);
                }
            }
        }
    }
}

int find_min_cost(void)
{
    int ret = INF;

    for (int col=1;col<=M;col++) {
        for (int d=1;d<=NUM_OF_DIRS;d++) {
            ret = min(ret,dp[N][col][d]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    cout<<find_min_cost()<<'\n';

    return  0;
}