#include <iostream>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (40+1)

int R, C, grid[MAX_SIZE+1][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int cur_row, int cur_col) {
    int p = grid[cur_row][cur_col];

    grid[cur_row][cur_col] = 0;

    if (cur_row == R && cur_col == C) {
        return p;
    }

    int row, col, max_num_of_papaya;

    max_num_of_papaya = 0;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (grid[adj_row][adj_col] > max_num_of_papaya) {
            max_num_of_papaya = grid[adj_row][adj_col];
            row = adj_row, col = adj_col;
        }
    }

    return p + dfs(row, col);
}

void input(void) {
    cin >> R >> C;

    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= C; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << dfs(1, 1) << '\n';

    return 0;
}