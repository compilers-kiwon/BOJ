#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

typedef pair<int, int> Pos;
typedef tuple<Pos, int, int, int> State;

enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    MAX_DIR = 4, 
};

#define MAX_SPEED (100)
#define MAX_SIZE (100+1)
#define INF (MAX_SIZE*MAX_SIZE)

int N, blocked[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][MAX_DIR][MAX_SPEED];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define row first
#define col second

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_reachable(int s_row, int s_col, int e_row, int e_col, int dir, int t) {
    bool ret = true;

    for (; s_row != e_row || s_col != e_col;) {
        s_row += adj[dir].d_row;
        s_col += adj[dir].d_col;
        t += (s_row==e_row&&s_col==e_col)?1:0;

        if (blocked[s_row][s_col] != 0 && t >= blocked[s_row][s_col]) {
            ret = false;
            break;
        }
    }

    return ret;
}

int simulate(void) {
    int ret;
    queue<State> q;

    q.push({{1, 1}, RIGHT, 0, 0}), dp[1][1][RIGHT][0] = 0;
    q.push({{1, 1}, DOWN, 0, 0}), dp[1][1][DOWN][0] = 0;

    for (ret = INF; !q.empty(); q.pop()) {
        auto [cur_pos, cur_dir, cur_speed, cur_time] = q.front();

        if (cur_pos.row == N && cur_pos.col == N) {
            ret = min(ret, cur_time);
            continue;
        }

        for (int d= 0; d < MAX_DIR; ++d) {
            int adj_speed = (cur_dir==d)?cur_speed+1:1;
            int adj_row = cur_pos.row + (adj[d].d_row * adj_speed);
            int adj_col = cur_pos.col + (adj[d].d_col * adj_speed);
            int adj_time = cur_time + 1;

            if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, N)) {
                continue;
            }

            if (is_reachable(cur_pos.row, cur_pos.col,
                                adj_row, adj_col, d, cur_time) == false) {
                continue;
            }

            if (adj_time >= dp[adj_row][adj_col][d][adj_speed]) {
                continue;
            }

            q.push({{adj_row, adj_col}, d, adj_speed, adj_time});
            dp[adj_row][adj_col][d][adj_speed] = adj_time;
        }
    }

    return ret;
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col) {
            cin >> blocked[row][col];

            for (int d = 0; d < MAX_DIR; ++ d) {
                fill(&dp[row][col][d][0], &dp[row][col][d][MAX_SPEED], INF);
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_time;

    input();
    min_time = simulate();

    if (min_time == INF) {
        cout << "Fired\n";
    } else {
        cout << min_time << '\n';
    }

    return 0;
}