#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (500+1)
#define INF (0x7FFFFFFF)

#define UP (0)
#define DOWN (1)
#define LEFT (2)
#define RIGHT (3)
#define MAX_DIR (4)

#define NORMAL_MODE (0)
#define WARP_MODE (1)
#define MAX_NUM_OF_MODES (2)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct {
    char c;
    int adj_warp[MAX_DIR];
} Grid;

typedef struct {
    int mode, num_of_used_turns, row, col;
} State;

int N, t, r, c;
int dp[MAX_NUM_OF_MODES][MAX_SIZE][MAX_SIZE];
Grid grid[MAX_SIZE][MAX_SIZE];
vector<int> warp_in_row[MAX_SIZE], warp_in_col[MAX_SIZE];

#define update_dp(state) (dp[(state).mode][(state).row][(state).col]=(state).num_of_used_turns)
#define is_faster(state) ((state).num_of_used_turns<dp[(state).mode][(state).row][(state).col])

void analyze(void) {
    for (int row = 1; row <= N; row++) {
        int left_warp = 0;

        for (int col = 1; col <= N; col++) {
            grid[row][col].adj_warp[LEFT] = left_warp;

            if (grid[row][col].c == '#') {
                left_warp = col;
            }
        }

        int right_warp = 0;

        for (int col = N; col >= 1; col--) {
            grid[row][col].adj_warp[RIGHT] = right_warp;

            if (grid[row][col].c == '#') {
                right_warp = col;
            }
        }
    }

    for (int col = 1; col <= N; col++) {
        int up_warp = 0;

        for (int row = 1; row <= N; row++) {
            grid[row][col].adj_warp[UP] = up_warp;

            if (grid[row][col].c == '#') {
                up_warp = row;
            }
        }

        int down_warp = 0;

        for (int row = N; row >= 1; row--) {
            grid[row][col].adj_warp[DOWN] = down_warp;

            if (grid[row][col].c == '#') {
                down_warp = row;
            }
        }
    }
}

int simulate(void) {
    queue<State> q;
    State init = {NORMAL_MODE, 0, 1, 1};

    q.push(init);
    update_dp(init);

    for (; !q.empty(); q.pop()) {
        State cur = q.front();
        State next;

        if (cur.row == r && cur.col == c) {
            continue;
        }

        if (cur.mode == NORMAL_MODE) {
            for (int d = 0; d < MAX_DIR; d++) {
                int adj_row = cur.row + adj[d].d_row;
                int adj_col = cur.col + adj[d].d_col;

                if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, N)) {
                    continue;
                }

                next = {NORMAL_MODE, cur.num_of_used_turns + 1, adj_row, adj_col};

                if (is_faster(next)) {
                    q.push(next), update_dp(next);
                }
            }

            next = {WARP_MODE, cur.num_of_used_turns + t, cur.row, cur.col};

            if (is_faster(next)) {
                q.push(next), update_dp(next);
            }
        } else {
            for (int d = 0; d < MAX_DIR; d++) {
                if (grid[cur.row][cur.col].adj_warp[d] != 0) {
                    next = {WARP_MODE, cur.num_of_used_turns + 1,
                        (d==UP||d==DOWN)?grid[cur.row][cur.col].adj_warp[d]:cur.row,
                        (d==LEFT||d==RIGHT)?grid[cur.row][cur.col].adj_warp[d]:cur.col
                    };

                    if (is_faster(next)) {
                        q.push(next), update_dp(next);
                    }
                }
            }

            next = cur;
            next.mode = NORMAL_MODE;

            if (is_faster(next)) {
                q.push(next), update_dp(next);
            }
        }
    }

    return min(dp[NORMAL_MODE][r][c], dp[WARP_MODE][r][c]);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> t >> r >> c;

    for (int row = 1; row <= N; row++) {
        char s[MAX_SIZE+1];

        cin >> &s[1];

        for (int col = 1; col <= N; col++) {
            grid[row][col].c = s[col];
            dp[NORMAL_MODE][row][col] = dp[WARP_MODE][row][col] = INF;
        }
    }

    analyze();
    cout << simulate() << '\n';

    return 0;
}