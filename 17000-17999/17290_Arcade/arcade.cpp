#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> State;

#define MAX_DIR (4)
#define MAX_SIZE (10)

char grid[MAX_SIZE+1][MAX_SIZE+2];
bool visited[MAX_SIZE+1][MAX_SIZE+1];
bool safe_in_row[MAX_SIZE+1];
bool safe_in_col[MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void init(void) {
    fill(&safe_in_row[1], &safe_in_row[MAX_SIZE+1], true);
    fill(&safe_in_col[1], &safe_in_col[MAX_SIZE+1], true);
}

void input(int& r, int& c) {
    cin >> r >> c;

    for (int row = 1; row <= MAX_SIZE; ++row) {
        cin >> &grid[row][1];

        for (int col = 1; col <= MAX_SIZE; ++col) {
            if (grid[row][col] == 'o') {
                safe_in_row[row] = safe_in_col[col] = false;
            }    
        }
    }
}

int simulate(int r, int c) {
    int ret;
    queue<State> q;

    for (q.push({r, c, 0}), visited[r][c] = true; !q.empty(); q.pop()) {
        auto [cur_row, cur_col, cur_steps] = q.front();

        if (safe_in_row[cur_row] && safe_in_col[cur_col]) {
            ret = cur_steps;
            break;
        }

        for (int d = 0; d < MAX_DIR; ++d) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, MAX_SIZE)
                    || !IN_RANGE(1, adj_col, MAX_SIZE)) {
                continue;
            }

            if (visited[adj_row][adj_col] == true) {
                continue;
            }

            visited[adj_row][adj_col] = true;
            q.push({adj_row, adj_col, cur_steps + 1});
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int r, c;
    init(), input(r, c);
    cout << simulate(r, c) << '\n';

    return 0;
}