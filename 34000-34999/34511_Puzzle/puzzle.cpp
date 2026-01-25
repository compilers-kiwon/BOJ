#include <iostream>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (100+1)

int N, M;
char grid[MAX_SIZE][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; ++row) {
        cin >> &grid[row][1];
    }
}

int simulate(char from, char to) {
    int ret = 0;

    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= M; ++col) {
            if (grid[row][col] != from) {
                continue;
            }

            for (int d = 0; d < MAX_DIR; d++) {
                int adj_row = row + adj[d].d_row;
                int adj_col = col + adj[d].d_col;

                if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, M)) {
                    continue;
                }

                if (grid[adj_row][adj_col] != to) {
                    continue;
                }

                ++ret;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate('X', 'Y') << '\n';

    return 0;
}