#include <iostream>

using namespace std;

#define MAX_NUM (9)
#define MAX_DIR (4)
#define MAX_SIZE (3)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int, int> Pos;

const int grid[MAX_SIZE+1][MAX_SIZE+1] = {
    {0, 0, 0, 0}, {0, 1, 2, 3}, {0, 4, 5, 6}, {0, 7, 8, 9}
};

bool visited[MAX_SIZE+1][MAX_SIZE+1];

Pos get_pos(int n) {
    for (int row = 1; row <= MAX_SIZE; row++) {
        for (int col = 1; col <= MAX_SIZE; col++) {
            if (grid[row][col] == n) {
                return {row, col};
            }
        }
    }

    return {0, 0};
}

int dfs(Pos cur, int num_of_digits) {
    int cur_row = cur.first;
    int cur_col = cur.second;

    if (visited[cur_row][cur_col] == true) {
        return 0;
    }

    if (num_of_digits == MAX_NUM) {
        return 1;
    }

    visited[cur_row][cur_col] = true;

    const struct {
        int d_row, d_col;
    } adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int ret = 0;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, MAX_SIZE)
                || !IN_RANGE(1, adj_col, MAX_SIZE)) {
            continue;
        }

        ret += dfs({adj_row, adj_col}, num_of_digits + 1);
    }

    visited[cur_row][cur_col] = false;

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;

    cin >> K;
    cout << dfs(get_pos(K), 1) << '\n';

    return 0;
}