#include <iostream>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (5)

int r, c, grid[MAX_SIZE][MAX_SIZE];

#define IN_RANGE(p) (0<=(p)&&(p)<MAX_SIZE)

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

const int BLOCKED = -1;
const int available_steps = 3;
const int target_num_of_apples = 2;

bool dfs(int row, int col, int num_of_apples, int available) {
    num_of_apples += grid[row][col];

    if (num_of_apples == target_num_of_apples) {
        return true;
    }

    if (available == 0) {
        return false;
    }

    for (int d = 0; d < MAX_DIR; ++d) {
        int adj_row = row + adj[d].d_row;
        int adj_col = col + adj[d].d_col;

        if (!IN_RANGE(adj_row) || !IN_RANGE(adj_col)) {
            continue;
        }

        if (grid[adj_row][adj_col] == BLOCKED) {
            continue;
        }

        int tmp = grid[row][col];
        
        grid[row][col] = BLOCKED;

        if (dfs(adj_row, adj_col, num_of_apples, available - 1) == true) {
            return true;
        }

        grid[row][col] = tmp;
    }

    return false;
}

void input(void) {
    for (int row = 0; row < MAX_SIZE; ++row) {
        for (int col = 0; col < MAX_SIZE; ++col) {
            cin >> grid[row][col];
        }
    }

    cin >> r >> c;
}

int simulate(void) {
    return (dfs(r, c, 0, available_steps)?1:0);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}