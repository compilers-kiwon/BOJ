#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pos; // <row, col>

#define MAX_DIR (2)
#define MAX_SIZE (300+1)

int N, M, grid[MAX_SIZE][MAX_SIZE];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{1, 0}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool simuate(void) {
    bool ret;
    queue<Pos> q;

    for (q.push({1, 1}), grid[1][1] = 0, ret = false; !q.empty(); q.pop()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        if (cur_row == M && cur_col == N) {
            ret = true;
            break;
        }

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, M) || !IN_RANGE(1, adj_col, N)) {
                continue;
            }

            if (grid[adj_row][adj_col] == 0) {
                continue;
            }

            q.push({adj_row, adj_col}), grid[adj_row][adj_col] = 0;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= M; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << (simuate()?"Yes":"No") << '\n';

    return 0;
}