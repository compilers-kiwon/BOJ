#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAX_SIZE (8)

typedef struct {
    int num;
    vector<pair<int, int>> adj;
} Move;

typedef pair<char, pair <int, int>> Piece;

unordered_map<char, Move> piece_info = {
    {'K', {1, {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}}},
    {'Q', {MAX_SIZE, {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}}},
    {'R', {MAX_SIZE, {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}}},
    {'P', {1, {{1, -1}, {-1, -1}}}},
    {'B', {MAX_SIZE, {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},
    {'N', {1, {{-1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {2, 1}, {2, -1}}}},
};

bool grid[MAX_SIZE+1][MAX_SIZE+1];

#define get_idx(c) ((int)((c)-'A'))
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int simulate(Piece p) {
    int ret = 0;
    int num_of_moves = piece_info[p.first].num;
    vector<pair<int, int>>& adj = piece_info[p.first].adj;

    for (int d = 0; d < adj.size(); d++) {
        int cur_row = p.second.first;
        int cur_col = p.second.second;

        for (int step = 1; step <= num_of_moves; step++) {
            int adj_row = cur_row + (adj[d].first * step);
            int adj_col = cur_col + (adj[d].second * step);

            if (!IN_RANGE(1, adj_row, MAX_SIZE) || !IN_RANGE(1, adj_col, MAX_SIZE)) {
                break;
            }

            if (grid[adj_row][adj_col] == true) {
                ret++;
                break;
            }
        }
    }
 
    return ret;
}

void clear_grid(const vector<Piece>& p) {
    for (int i = 0; i < p.size(); i++) {
        int row = p[i].second.first;
        int col = p[i].second.second;
        grid[row][col] = false;
    }
}

void input(vector<Piece>& p) {
    int N;

    for (cin >> N; N > 0; N--) {
        char col, dash, t;
        int row;

        cin >> col >> row >> dash >> t;
        p.push_back({t, {row, MAX_SIZE - get_idx(col)}});
        grid[row][MAX_SIZE-get_idx(col)] = true;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int cnt = 0;
        vector<Piece> p;

        input(p);

        for (int i = 0; i < p.size(); i++) {
            cnt += simulate(p[i]);
        }

        cout << "Case #" << t << ": " << cnt << '\n';
        clear_grid(p);
    }

    return 0;
}