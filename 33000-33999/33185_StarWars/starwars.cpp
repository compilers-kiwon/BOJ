#include <iostream>

using namespace std;

#define MAX_DIR (3)
#define MAX_SIZE (50+1)

int n, m;
int dp[MAX_SIZE][MAX_SIZE+1];
char grid[MAX_SIZE][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, -1}, {-1, 0}, {-1, 1}};

int get_dp(int cur_row, int cur_col) {
    int ret = 0;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;
        ret = max(ret, dp[adj_row][adj_col]);
    }

    return (ret += (grid[cur_row][cur_col]=='B')?1:0);
}

void input(void) {
    cin >> n >> m;

    for (int row = 1; row <= n; row++) {
        cin >> &grid[row][1];
    }
}

int simulate(void) {
    int ret = 0;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            dp[row][col] = get_dp(row, col);
            
            if (grid[row][col] == 'W') {
                ret = max(ret, dp[row][col]);
                dp[row][col] = 0;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}