#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_DIR (4)
#define MAX_SIZE (10+1)
#define MAX_STR_LEN (8)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const char str[MAX_STR_LEN] =
    {'Y', 'O', 'K', 'O', 'H', 'A', 'M', 'A'};

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef long long int int64;

int n, m;
char grid[MAX_SIZE][MAX_SIZE+1];
int64 dp[MAX_SIZE][MAX_SIZE][MAX_STR_LEN];

int64 get_dp(int row, int col, int pos) {
    if (pos == 0) {
        return 1;
    }

    int64& ret = dp[row][col][pos];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = row + adj[d].d_row;
        int adj_col = col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, n) || !IN_RANGE(1, adj_col, m)) {
            continue;
        }

        if (grid[adj_row][adj_col] != str[pos-1]) {
            continue;
        }

        ret += get_dp(adj_row, adj_col, pos - 1);
    }

    return ret;
}

void input(void) {
    cin >> n >> m;

    for (int row = 1; row <= n; row++) {
        cin >> &grid[row][1];

        for (int col = 1; col <= m; col++) {
            fill(&dp[row][col][0], &dp[row][col][MAX_STR_LEN], TBD);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 ans = 0;

    input();

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (grid[row][col] == str[MAX_STR_LEN-1]) {
                ans += get_dp(row, col, MAX_STR_LEN - 1);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}