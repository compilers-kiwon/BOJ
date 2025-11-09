#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define NONE (0)
#define MAX_DIR (4)

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int R, C;
vector<string> tower;
vector<vector<int>> language;

static inline bool in_range(int row, int col) {
    if (row < 0 || row >= R) {
        return false;
    }

    if (col < 0 || col >= C) {
        return false;
    }

    return true;
}

void read_tower(void) {
    cin >> R >> C;

    for (int row = 0; row < R; row++) {
        string f;

        cin >> f;
        tower.push_back(f);
        language.push_back(vector<int>(C, NONE));
    }
}

void dfs(int row, int col, int idx, char cur_lang) {
    language[row][col] = idx;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = row + adj[d].d_row;
        int adj_col = col + adj[d].d_col;

        if (in_range(adj_row, adj_col) == false
            || language[adj_row][adj_col] != NONE
            || tower[adj_row][adj_col] != cur_lang) {
            continue;
        }

        dfs(adj_row, adj_col, idx, cur_lang);
    }
}

void build_language_map(void) {
    int idx = 1;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (language[row][col] != NONE) {
                continue;
            }

            dfs(row, col, idx++, tower[row][col]);
        }
    }
}

void do_query(void) {
    int Q;

    for (cin >> Q; Q > 0; Q--) {
        int r1, c1, r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        if (language[r1][c1] != language[r2][c2]) {
            cout << "N\n";
        } else {
            cout << tower[r1][c1] << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_tower();
    build_language_map();
    do_query();

    return 0;
}