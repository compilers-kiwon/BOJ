#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_DIR (4)
#define MAX_SIZE (1000+1)

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int r, d;
int grid[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE];

int input(void) {
    int S;

    cin >> S;
    r = (S * S) + 1, d = 0;

    for (int row = 1; row <= S; row++) {
        for (int col = 1; col <= S; col++) {
            cin >> grid[row][col], visited[row][col] = 0;
        }
    }

    return S;
}

int dfs(int row, int col, int size) {
    int& ret = visited[row][col];

    ret = 1;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = row + adj[d].d_row;
        int adj_col = col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, size) || !IN_RANGE(1, adj_col, size)) {
            continue;
        }

        if ((grid[row][col] + 1) == grid[adj_row][adj_col]) {
            ret += dfs(adj_row, adj_col, size);
        }
    }

    if (ret >= d) {
        if (ret == d) {
            r = min(r, grid[row][col]);
        } else {
            r = grid[row][col];
        }

        d = ret;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int size = input();

        for (int row = 1; row <= size; row++) {
            for (int col = 1; col <= size; col++) {
                if (visited[row][col] == 0) {
                    dfs(row, col, size);
                }
            }
        }

        cout << "Case #" << t << ": "
                << r << ' ' << d << '\n';
    }

    return 0;
}