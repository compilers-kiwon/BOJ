#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int N, M, grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            int R, G, B;
            cin >> R >> G >> B;
            grid[row][col] = (R << 16) + (G << 8) + B;
        }
    }
}

int dfs(int cur_row, int cur_col, int color) {
    if (!IN_RANGE(1, cur_row, N) || !IN_RANGE(1, cur_col, M)) {
        return 0;
    }

    if (visited[cur_row][cur_col] == true
            || color != grid[cur_row][cur_col]) {
        return 0;
    }

    visited[cur_row][cur_col] = true;

    for (int d_row = -1; d_row <= 1; d_row++) {
        for (int d_col = -1; d_col <= 1; d_col++) {
            int adj_row = cur_row + d_row;
            int adj_col = cur_col + d_col;
            dfs(adj_row, adj_col, color);
        }
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;

    input();

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            cnt += dfs(row, col, grid[row][col]);
        }
    }

    cout << cnt << '\n';

    return 0;
}