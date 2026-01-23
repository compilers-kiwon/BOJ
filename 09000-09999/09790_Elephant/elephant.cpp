#include <iostream>
#include <queue>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (40+1)

int W, H;
char grid[MAX_SIZE][MAX_SIZE+1];

typedef pair<int, int> Pos;

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool input(Pos& e) {
    bool found = false;

    cin >> W >> H;

    if (W == 0 && H == 0) {
        return false;
    }

    for (int row = 1; row <= H; ++row) {
        cin >> &grid[row][1];

        if (found == false) {
            for (int col = 1; col <= W; ++col) {
                if (grid[row][col] == 'A') {
                    found = true;
                    e = {row, col}, grid[row][col] = '#';
                }
            }
        }
    }

    return true;
}

int simulate(Pos& e) {
    int ret;
    queue<Pos> q;

    for (ret = 1, q.push(e); !q.empty(); q.pop()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for (int d = 0; d < MAX_DIR; ++d) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, H) || !IN_RANGE(1, adj_col, W)) {
                continue;
            }

            if (grid[adj_row][adj_col] == '#') {
                continue;
            }

            q.push({adj_row, adj_col}), grid[adj_row][adj_col] = '#';
            ++ret;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;) {
        Pos elephant;

        if (input(elephant) == false) {
            break;
        }

        cout << simulate(elephant) << '\n';
    }

    return 0;
}