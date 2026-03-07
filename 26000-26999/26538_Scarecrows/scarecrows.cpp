#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> Scarecrow;

void input(vector<string>& grid,
            vector<Scarecrow>& s) {
    int w, h, q;

    cin >> w >> h >> q;

    for (int row = 0; row < h; ++row) {
        string str(h, '.');
        grid.push_back(str);
    }

    for (int i = 0; i < q; ++i) {
        int r, c, p;
        cin >> r >> c >> p;
        s.push_back({r, c, p}), grid[c][r] = 'x';
    }
}

void simulate(vector<string>& grid) {
    vector<Scarecrow> s;

    input(grid, s);

    int row_size = grid.size();
    int col_size = grid.front().size();

    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            if (grid[row][col] != '.') {
                continue;
            }

            for (int i = 0; i < s.size(); ++i) {
                auto [s_col, s_row, s_range] = s[i];
                int d_row = row - s_row;
                int d_col = col - s_col;

                if (abs(d_row) + abs(d_col) <= s_range) {
                    grid[row][col] = '*';
                    break;
                }
            }
        }
    }
}

void print(const vector<string>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        cout << grid[i] << '\n';
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; --n) {
        vector<string> grid;
        simulate(grid);
        print(grid);
    }

    return 0;
}