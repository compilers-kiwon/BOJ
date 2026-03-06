#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TBD (-1)
#define TRUE (1)
#define FALSE (0)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

const struct {
    int d_row, d_col;
} adj[2] = {{-1, 0}, {0, -1}};

int get_dp(int row, int col, int size,
            const vector<string>& grid, vector<vector<int>>& dp) {
    if (row == 0 && col == 0) {
        return TRUE;
    }

    int& ret = dp[row][col];

    if (ret != TBD) {
        return ret;
    }

    ret = FALSE;

    for (int i = 0; i < 2; ++i) {
        int adj_row = row + adj[i].d_row;
        int adj_col = col + adj[i].d_col;

        if (!IN_RANGE(0, adj_row, size) || !IN_RANGE(0, adj_col, size)) {
            continue;
        }

        if (grid[adj_row][adj_col] == 'x') {
            continue;
        }
        
        if ((ret = get_dp(adj_row, adj_col, size, grid, dp)) == TRUE) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    
    cin >> N;

    vector<string> grid;
    vector<vector<int>> dp;

    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        grid.push_back(s), dp.push_back(vector<int>(N, TBD));
    }

    cout << (get_dp(N - 1, N - 1, N, grid, dp)?"Yes":"No") << '\n';

    return 0;
}