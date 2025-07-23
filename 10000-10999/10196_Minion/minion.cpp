#include <iostream>

using namespace std;

#define MAX_SIZE (20+1)
#define MAX_DIR (4)

static inline bool in_range(int MIN, int n, int MAX) {
    return ((MIN <= n) && (n <= MAX));
}

static inline void print_bondary(int width) {
    for (int col = 1; col <= width; col++) {
        cout << "+---";
    }

    cout << "+\n";
}

char grid[MAX_SIZE+1][MAX_SIZE+1];
bool visited[MAX_SIZE][MAX_SIZE];

char get_state(int row, int col) {
    if (grid[row][col] == 'X') {
        return 'X';
    }

    if (visited[row][col] == true) {
        return 'M';
    }

    return ' ';
}

void dfs(int cur_row, int cur_col, int height, int width) {
    if (grid[cur_row][cur_col] == 'X' ||
            visited[cur_row][cur_col] == true) {
        return;
    }

    visited[cur_row][cur_col] = true;

    const struct {int d_row, d_col;} adj[MAX_DIR] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (in_range(1, adj_row, height) && in_range(1, adj_col, width)) {
            dfs(adj_row, adj_col, height, width);
        }
    }
}


void print_grid(int height, int width) {
    for (int row = 1; row <= height; row++) {
        print_bondary(width);

        for (int col = 1; col <= width; col++) {
            cout << "| "<< get_state(row, col) <<' ';
        }
        cout << "|\n";
    }

    print_bondary(width);

    if (visited[height][width] == true) {
        cout << "Minions can cross the room\n";
    } else {
        cout << "Minions cannot cross the room\n";
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int H, W;

        cin >> H >> W;

        for (int row = 1; row <= H; row++) {
            cin >> &grid[row][1];
            fill(&visited[row][1], &visited[row][W+1], false);
        }

        dfs(1, 1, H, W);

        cout << "Case: " << t <<'\n';
        print_grid(H, W);
    }

    return 0;
}