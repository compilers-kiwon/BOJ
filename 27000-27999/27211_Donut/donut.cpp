#include    <iostream>

using namespace std;

const static int MAX_SIZE = 1000;
const static int MAX_DIR = 4;

const static int d_row[MAX_DIR] = {-1,1,0,0};
const static int d_col[MAX_DIR] = {0,0,-1,1};

const static int EMPTY = 0;
const static int BLOCKED = 1;

static inline int get_adj_row(int cur,int dir,int size) {
    return  (cur+d_row[dir]+size)%size;
}

static inline int get_adj_col(int cur,int dir,int size) {
    return  (cur+d_col[dir]+size)%size;
}

static int N,M,grid[MAX_SIZE][MAX_SIZE];
static bool visited[MAX_SIZE][MAX_SIZE];

static inline bool is_available(int row,int col) {
    return (grid[row][col]==EMPTY && visited[row][col]==false);
}

void input(void)
{
    cin>>N>>M;

    for (int row=0;row<N;row++) {
        for (int col=0;col<M;col++) {
            cin>>grid[row][col];
        }
    }
}

void dfs(int cur_row,int cur_col)
{
    for (int d=0;d<MAX_DIR;d++) {
        int adj_row = get_adj_row(cur_row,d,N);
        int adj_col = get_adj_col(cur_col,d,M);

        if (is_available(adj_row,adj_col) == true) {
            visited[adj_row][adj_col] = true;
            dfs(adj_row,adj_col);
        }
    }
}

int simmulate(void)
{
    int ret = 0;

    for (int row=0;row<N;row++) {
        for (int col=0;col<M;col++) {
            if (is_available(row,col) == true) {
                visited[row][col] = true;
                dfs(row,col);
                ret++;
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
    cout<<simmulate()<<'\n';

    return  0;
}