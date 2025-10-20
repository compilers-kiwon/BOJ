#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)
#define MAX_DIR (4)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int, int> Pos;

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char grid[MAX_SIZE+1][MAX_SIZE+1];
bool visited[MAX_SIZE][MAX_SIZE];
int N, M, map[MAX_SIZE][MAX_SIZE];

void read_map(void) {
    queue<Pos> q;

    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];

        for (int col = 1; col <= M; col++) {
            if (row == 1 || row == N || col == 1 || col == M) {
                q.push({row, col});
                visited[row][col] = true;
            }
        }
    }

    for (; !q.empty(); q.pop()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, M)) {
                continue;
            }

            if (visited[adj_row][adj_col] == true || grid[adj_row][adj_col] == '1') {
                continue;
            }

            visited[adj_row][adj_col] = true;
            q.push({adj_row, adj_col});
        }
    }
}

void convert_map(void) {
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            map[row][col] = map[row][col-1] + (visited[row][col]?0:1);
        }
    }

    for (int col = 1; col <= M; col++) {
        for (int row = 1; row <= N; row++) {
            map[row][col] += map[row-1][col];
        }
    }
}

void do_query(void) {
    int Q;

    for (cin >> Q; Q > 0; Q--) {
        int r1, c1, r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        int up = map[r1-1][c2];
        int left = map[r2][c1-1];
        int shared = map[r1-1][c1-1];
        int total = map[r2][c2];

        if (total == (up + left - shared)) {
            cout << "Yes\n";
        } else {
            cout << "No " << total - (up + left - shared) << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_map();
    convert_map();
    do_query();

    return 0;
}