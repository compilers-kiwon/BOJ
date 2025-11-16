#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define INF (0x7FFFFFFF)
#define MAX_SIZE (1000+1)

typedef pair<int, int> Pos; // <row, col>
typedef pair<int, Pos> State; // <num_of_cracks, Pos>

#define row first
#define col second

int N, L, K, dp[MAX_SIZE][MAX_SIZE+1];
Pos prev_pos[MAX_SIZE][MAX_SIZE+1];
char grid[MAX_SIZE][MAX_SIZE+1];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(void) {
    cin >> N >> L >> K;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];
        fill (&dp[row][1], &dp[row][L+2], INF);
    }
}

Pos simulate(void) {
    Pos ret;
    int min_cracks = INF;
    queue<State> q;

    for (q.push({0, {K, 1}}); !q.empty(); q.pop()) {
        int cur_cracks = q.front().first;
        Pos cur_pos = q.front().second;

        if (cur_pos.col == (L + 1)) {
            if (min_cracks > cur_cracks) {
                ret = cur_pos;
                min_cracks = cur_cracks;
            }

            continue;
        }

        State s;
        vector<State> next;
        char c = grid[cur_pos.row][cur_pos.col];

        switch (c) {
            case '=':
            case 'H':
                s.first = cur_cracks + ((c=='H')?1:0);
                s.second.row = cur_pos.row;
                s.second.col = cur_pos.col + 1;
                next.push_back(s);
                break;
            case '^':
            case 'v':
                s.first = cur_cracks;
                s.second.row = cur_pos.row;
                s.second.col = cur_pos.col + 1;
                next.push_back(s);

                s.second.row = cur_pos.row + ((c=='^')?-1:1);
                s.second.col = cur_pos.col;
                next.push_back(s);
                break;
            default:
                // do nothing
                break;
        }

        for (int i = 0; i < next.size(); i++) {
            State& adj = next[i];

            if (!IN_RANGE(1, adj.second.row, N)) {
                continue;
            }

            if (adj.first < dp[adj.second.row][adj.second.col]) {
                dp[adj.second.row][adj.second.col] = adj.first;
                prev_pos[adj.second.row][adj.second.col] = cur_pos;
                q.push(adj);
            }
        }
    }

    return ret;
}

void backtrace(int row, int col) {
    vector<pair<int, char>> path;

    for (;row != K || col != 1;) {
        int prev_row = prev_pos[row][col].row;
        int prev_col = prev_pos[row][col].col;

        if (row != prev_row) {
            path.push_back({col, (prev_row < row)?'d':'u'});
        }

        row = prev_row, col = prev_col;
    }

    for (auto it = path.rbegin(); it != path.rend(); it++) {
        cout << it->first << it->second << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos p;

    input();
    p = simulate();

    cout << dp[p.row][p.col] << '\n';
    backtrace(p.row, p.col - 1);

    return 0;
}