#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

const string target = "word";

int simulate(int row, int col,
                const vector<string>& grid) {
    int ret = 0;
    int row_size = grid.size();
    int col_size = grid.front().length();

    for (int d_row = -1; d_row <= 1; d_row++) {
        for (int d_col = -1; d_col <= 1; d_col++) {
            string cur;

            for (int i = 0; i < target.length(); i++) {
                int adj_row = row + (d_row * i);
                int adj_col = col + (d_col * i);

                if (!IN_RANGE(0, adj_row, row_size) ||
                        !IN_RANGE(0, adj_col, col_size)) {
                    break;
                }

                cur.push_back(grid[adj_row][adj_col]);
            }

            if (cur == target) {
                ret++;
            }
        }
    }

    return ret;
}

int search(const vector<string>& grid) {
    int row_size = grid.size();
    int col_size = grid.front().length();
    int ret = 0;
    
    for (int row = 0; row < row_size; row++) {
        for (int col = 0; col < col_size; col++) {
            ret += simulate(row, col, grid);
        }
    }
    return ret;
}

void input(vector<string>& grid) {
    int r, c;

    cin >> r >> c;

    for (int row = 0; row < r; row++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        vector<string> grid;

        input(grid);
        cout << search(grid) << '\n';
    }

    return 0;
}