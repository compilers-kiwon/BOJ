#include <iostream>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (90+1)

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int m, n, grid[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void dfs(int cur_row, int cur_col, int cur_len, int& max_len) {
    max_len = max(max_len, cur_len);

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, n) || !IN_RANGE(1, adj_col, m)) {
            continue;
        }

        if (grid[adj_row][adj_col] == 0) {
            continue;
        }

        grid[adj_row][adj_col] = 0;
        dfs(adj_row, adj_col, cur_len + 1, max_len);
        grid[adj_row][adj_col] = 1;
    }
}

void input(void) {
    cin >> m >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_len = 0;

    input();

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (grid[row][col] == 1) {
                grid[row][col] = 0;
                dfs(row, col, 1, max_len);
                grid[row][col] = 1;
            }
        }
    }

    cout << max_len << '\n';

    return 0;
}