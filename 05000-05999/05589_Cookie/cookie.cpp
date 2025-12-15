#include <iostream>
#include <vector>

using namespace std;

#define MAX_ROW (10+1)
#define MAX_COL (10000+1)

int R, C, grid[MAX_ROW][MAX_COL];

int count_num_of_backside(void) {
    int ret = 0;

    for (int col = 1; col <= C; col++) {
        int num_of_frontside = 0;

        for (int row = 1; row <= R; row++) {
            num_of_frontside += grid[row][col];
        }

        ret += max(num_of_frontside, R - num_of_frontside);
    }

    return ret;
}

void reverse_rows(const vector<int>& rows) {
    for (int i = 0; i < rows.size(); i++) {
        for (int col = 1; col <= C; col++) {
            grid[rows[i]][col] = (grid[rows[i]][col])?0:1;
        }
    }
}

void dfs(int cur_row, vector<int>& rows, int& max_cnt) {
    if (cur_row > R) {
        reverse_rows(rows);
        max_cnt = max(max_cnt, count_num_of_backside());
        reverse_rows(rows);

        return;
    }

    rows.push_back(cur_row);
    dfs(cur_row + 1, rows, max_cnt);
    rows.pop_back();

    dfs(cur_row + 1, rows, max_cnt);
}


void input(void) {
    cin >> R >> C;

    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= C; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_cnt = 0;
    vector<int> selected;

    input();
    dfs(1, selected, max_cnt);
    cout << max_cnt << '\n';

    return 0;
}