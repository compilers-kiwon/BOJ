#include <iostream>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (100+1)

int R, C, T;
char grid[MAX_SIZE][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(int& g_row, int& g_col) {
    cin >> R >> C >> T;

    for (int row = 1; row <= R; row++) {
        cin >> &grid[row][1];

        for (int col = 1; col <= C; col++) {
            if (grid[row][col] == 'G') {
                g_row = row, g_col = col;
                grid[row][col] = '.';
            }
        }
    }
}

void dfs(int cur_row, int cur_col, int num_of_moves,
            int cur_num_of_potato, int& max_num_of_potato) {
    if (num_of_moves == T) {
        max_num_of_potato = max(max_num_of_potato, cur_num_of_potato);
        return;
    }

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, R) || !IN_RANGE(1, adj_col, C)) {
            continue;
        }

        switch (grid[adj_row][adj_col]) {
            case '.':
                dfs(adj_row, adj_col, num_of_moves + 1,
                        cur_num_of_potato, max_num_of_potato);
                break;
            case 'S':
                grid[adj_row][adj_col] = '.';
                dfs(adj_row, adj_col, num_of_moves + 1,
                        cur_num_of_potato + 1, max_num_of_potato);
                grid[adj_row][adj_col] = 'S';
                break;
            case '#':
            default :
                // do nothing
                break;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int s_row, s_col, max_num;

    input(s_row, s_col), max_num = 0;
    dfs(s_row, s_col, 0, 0, max_num);
    cout << max_num << '\n';

    return 0;
}