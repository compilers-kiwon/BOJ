#include    <iostream>

using namespace std;

const static int MAX_SIZE = (10+1);
const static int MAX_DIR = 4;
const static int AVAILABLE = 0;
const static int ALLOC = 1;
const static int FREE = -1;
const static int MIN_INF = -1000000;

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

static int N,M,K;
static int grid[MAX_SIZE][MAX_SIZE];
static int state[MAX_SIZE+1][MAX_SIZE+1];

static inline void change_state(int row,int col,int s)
{
    state[row][col] += s;

    for (int d=0;d<MAX_DIR;d++) {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;
        state[adj_row][adj_col] += s;
    }
}

void simulate(int cur_sum,int size,int& max_sum)
{
    if (size == K) {
        max_sum = max(max_sum,cur_sum);
        return;
    }

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            if (state[row][col] == AVAILABLE) {
                change_state(row,col,ALLOC);
                simulate(cur_sum+grid[row][col],size+1,max_sum);
                change_state(row,col,FREE);
            }
        }
    }
}

void input(void)
{
    cin>>N>>M>>K;

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            cin>>grid[row][col];
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_sum = MIN_INF;

    input();
    simulate(0,0,max_sum);
    cout<<max_sum<<'\n';

    return  0;
}