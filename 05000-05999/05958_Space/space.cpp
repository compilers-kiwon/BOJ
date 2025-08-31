#include <iostream>
#include <queue>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (1000+1)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int, int> Pos; // <row, col>

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};

int N;
char grid[MAX_SIZE][MAX_SIZE+1];

void bfs(int row, int col) {
    queue<Pos> q;

    for (q.push({row, col}), grid[row][col] = '.'; !q.empty(); q.pop()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, N)) {
                continue;
            }

            if (grid[adj_row][adj_col] == '*') {
                q.push({adj_row,adj_col}), grid[adj_row][adj_col] = '.';
            }
        }
    }
}

int count_asteroids(void) {
    int ret = 0;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            if (grid[row][col] == '*') {
                ret++, bfs(row, col);
            }
        }
    }

    return ret;
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << count_asteroids() << '\n';

    return 0;
}