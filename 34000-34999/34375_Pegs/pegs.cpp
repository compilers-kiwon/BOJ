#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

unordered_set<string> visited;

#define NONE (-1)
#define MAX_DIR (6)
#define MAX_SIZE (5)
#define INF (0x7FFFFFFF)

typedef struct {
    int d_row, d_col;
} Adj;

const Adj adj_mid[MAX_DIR] =
    {{-1, -1}, {1, 1}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
const Adj adj_end[MAX_DIR] =
    {{-2, -2}, {2, 2}, {0, 2}, {0, -2}, {-2, 0}, {2, 0}};

string input(void) {
    string ret;

    for (int row = 0; row < MAX_SIZE; row++) {
        for (int col = 0; col < row + 1; col ++) {
            char c;
            cin >> c;
            ret.push_back(c);
        }
    }

    return ret;
}

pair<int, int> conver_1d_to_2d(int pos) {
    int i = 0;

    for (int row = 0; row < MAX_SIZE; row++) {
        for (int col = 0; col < row + 1; col++) {
            if (i++ == pos) {
                return {row, col};
            }
        }
    }

    return {NONE, NONE};
}

int convert_2d_to_1d(int r, int c) {
    int i = 0;

    for (int row = 0; row < MAX_SIZE; row++) {
        for (int col = 0; col < row + 1; col++) {
            if (row == r && col == c) {
                return i;
            }

            i++;
        }
    }

    return NONE;
}

int count_pegs(const string& state) {
    int ret = 0;

    for (int i = 0; i < state.length(); i++) {
        ret += (state[i]=='X')?1:0;
    }

    return ret;
}

int simulate(const string& start) {
    int ret = INF;
    queue<string> q;

    for (q.push(start), visited.insert(start); !q.empty(); q.pop()) {
        string cur_state = q.front();

        ret = min(ret, count_pegs(cur_state));

        for (int i = 0; i < cur_state.length(); i++) {
            if (cur_state[i] == 'X') {
                continue;
            }

            pair<int, int> cur_2d_pos = conver_1d_to_2d(i);

            for (int d = 0; d < MAX_DIR; d++) {
                int mid_row = cur_2d_pos.first + adj_mid[d].d_row;
                int mid_col = cur_2d_pos.second + adj_mid[d].d_col;
                int mid_pos = convert_2d_to_1d(mid_row, mid_col);

                if (mid_pos == NONE || cur_state[mid_pos] != 'X') {
                    continue;
                }

                int end_row = cur_2d_pos.first + adj_end[d].d_row;
                int end_col = cur_2d_pos.second + adj_end[d].d_col;
                int end_pos = convert_2d_to_1d(end_row, end_col);

                if (end_pos == NONE || cur_state[end_pos] != 'X') {
                    continue;
                }

                string next_state = cur_state;
                
                next_state[mid_pos] = '-';
                swap(next_state[i], next_state[end_pos]);


                if (visited.find(next_state) == visited.end()) {
                    q.push(next_state);
                    visited.insert(next_state);
                }
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string p = input();
    cout << simulate(p) << '\n';

    return 0;
}