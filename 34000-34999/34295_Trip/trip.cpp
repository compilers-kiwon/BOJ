#include <iostream>
#include <queue>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define INF (0x7FFFFFFF)
#define MAX_SIZE (500+1)

enum {
    LOW = 0,
    HIGH = 1,
    MAX_DIR = 2
};

#define NEXT_DIR(d) (((d)+1)%MAX_DIR)

typedef struct {
    int dir, row, col;
} State;

int s_row, s_col, e_row, e_col;
int row_size, col_size, h[MAX_SIZE][MAX_SIZE];
int dp[MAX_DIR][MAX_SIZE][MAX_SIZE];

int simulate(void) {
    int ret = -1;
    queue<State> q;

    q.push({LOW, s_row, s_col}), dp[LOW][s_row][s_col] = 0;
    q.push({HIGH, s_row, s_col}), dp[HIGH][s_row][s_col] = 0;

    for (; !q.empty(); q.pop()) {
        int cur_dir = q.front().dir;
        int cur_row = q.front().row;
        int cur_col = q.front().col;

        if (cur_row == e_row && cur_col == e_col) {
            ret = dp[cur_dir][cur_row][cur_col];
            break;
        }

        for (int d_row = -1; d_row <= 1; d_row++) {
            for (int d_col = -1; d_col <= 1; d_col++) {
                int adj_dir = NEXT_DIR(cur_dir);
                int adj_row = cur_row + d_row;
                int adj_col = cur_col + d_col;

                if (!IN_RANGE(1, adj_row, row_size) || !IN_RANGE(1, adj_col, col_size)) {
                    continue;
                }

                int cur_height = h[cur_row][cur_col];
                int adj_height = h[adj_row][adj_col];

                if ((adj_dir == LOW && cur_height <= adj_height) ||
                        (adj_dir == HIGH && cur_height >= adj_height)) {
                    continue;
                }

                if (dp[adj_dir][adj_row][adj_col] != INF) {
                    continue;
                }

                q.push({adj_dir, adj_row, adj_col});
                dp[adj_dir][adj_row][adj_col] =
                    dp[cur_dir][cur_row][cur_col] + 1;
            }
        }
    }

    return ret;
}

void input(void) {
    cin >> row_size >> col_size;

    for (int row = 1; row <= row_size; row++) {
        for (int col = 1; col <= col_size; col++) {
            cin >> h[row][col];
            dp[LOW][row][col] = dp[HIGH][row][col] = INF; 
        }
    }

    cin >> s_row >> s_col >> e_row >> e_col;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}