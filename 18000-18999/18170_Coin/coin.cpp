#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE (20+2)
#define MAX_DIR (4)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};

int N, M, row1, col1, row2, col2;
int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
char grid[MAX_SIZE][MAX_SIZE];

typedef tuple<int, int, int, int, int> State;

bool in_range(int row, int col) {
    return IN_RANGE(1, row, N) && IN_RANGE(1, col, M);
}

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];

        for (int col = 1; col <= M; col++) {
            if (grid[row][col] == 'o') {
                if (row1 == 0 && col1 == 0) {
                    row1 = row, col1 = col;
                } else {
                    row2 = row, col2 = col;
                }
            }

            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= M; c++) {
                    visited[row][col][r][c] = -1;
                }
            }
        }
    }
}

int simulate(void) {
    int ret;
    queue<State> q;

    visited[row1][col1][row2][col2] = 0;
    q.push({0, row1, col1, row2, col2});

    for (ret = -1; !q.empty(); q.pop()) {
        auto [cur_num, cur_row1, cur_col1, cur_row2, cur_col2] = q.front();

        if (!in_range(cur_row1, cur_col1) || !in_range(cur_row2, cur_col2)) {
            if ((in_range(cur_row1, cur_col1) && !in_range(cur_row2, cur_col2)) ||
                    (!in_range(cur_row1, cur_col1) && in_range(cur_row2, cur_col2))) {
                ret = cur_num;
                break;
            }
            continue;
        }

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row1 = cur_row1 + adj[d].d_row;
            int adj_col1 = cur_col1 + adj[d].d_col;
            int adj_row2 = cur_row2 + adj[d].d_row;
            int adj_col2 = cur_col2 + adj[d].d_col;

            if (in_range(adj_row1, adj_col1) && in_range(adj_row2, adj_col2)) {
                if (grid[adj_row1][adj_col1] == '#') {
                    adj_row1 = cur_row1, adj_col1 = cur_col1;
                }
                
                if (grid[adj_row2][adj_col2] == '#') {
                    adj_row2 = cur_row2, adj_col2 = cur_col2;
                }

                if (visited[adj_row1][adj_col1][adj_row2][adj_col2] == -1) {
                    visited[adj_row1][adj_col1][adj_row2][adj_col2] = cur_num + 1;
                    q.push({cur_num + 1, adj_row1, adj_col1, adj_row2, adj_col2});
                }
            } else {
                if (visited[adj_row1][adj_col1][adj_row2][adj_col2] == 0) {
                    visited[adj_row1][adj_col1][adj_row2][adj_col2] = cur_num + 1;
                    q.push({cur_num + 1, adj_row1, adj_col1, adj_row2, adj_col2});
                }
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