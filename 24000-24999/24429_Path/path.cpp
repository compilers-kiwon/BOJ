#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos; // <row, col>

#define MAX_SIZE (1000+1)

int n, grid[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

void input(vector<Pos>& stops) {
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin >> grid[row][col];
        }
    }

    int P;

    for (cin >> P; P > 0; P--) {
        Pos s;
        cin >> s.first >> s.second;
        stops.push_back(s);
    }

    stops.push_back({n, n});
}

int get_dp(int row, int col, int up, int left) {
    if (row < up || col < left) {
        return 0;
    }

    int& ret = dp[row][col];

    if (ret != 0) {
        return ret;
    }

    ret = grid[row][col] +
            max(get_dp(row - 1, col, up, left),
                get_dp(row, col - 1, up, left));
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> stops;

    input(stops);
    sort(stops.begin(), stops.end());

    Pos cur = {1, 1};

    for (int i = 0; i < stops.size(); i++) {
        Pos end = stops[i];

        if (!(cur.first <= end.first && cur.second <= end.second)) {
            cout << "-1\n";
            return 0;
        }

        get_dp(end.first, end.second, cur.first, cur. second);
        cur = end;
    }

    cout << dp[n][n] << '\n';
    return 0;
}