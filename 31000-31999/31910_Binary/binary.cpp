#include <iostream>

using namespace std;

#define MAX_SIZE (30+1)
#define TBD (-1)

typedef long long int int64;

int N;
int64 grid[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

int64 get_dp(int row, int col) {
    if (row == 0 || col == 0) {
        return 0;
    }

    int64& ret = dp[row][col];

    if (ret != TBD) {
        return ret;
    }

    ret = grid[row][col] +
            (max(get_dp(row - 1, col), get_dp(row, col - 1)) << 1LL);
    
    return ret;
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            dp[row][col] = TBD;
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << get_dp(N, N) << '\n';

    return 0;
}