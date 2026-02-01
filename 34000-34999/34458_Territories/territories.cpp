#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (20000+1)
#define INF (1000000LL*1000000LL*1000000LL)

int64 dp[2][MAX_SIZE+1];

int64 simulate(int row_size, int col_size, int64 max_val) {
    int cur_ptr = 1;
    int64 cur_val = 1LL;

    dp[0][0] = dp[0][col_size+1] =
        dp[1][0] = dp[1][col_size+1] = INF;

    for (int row = 1; row <= row_size; ++row) {
        int prev_ptr = (cur_ptr + 1) % 2;

        for (int col = 1; col <= col_size; ++col) {
            int64 left = dp[prev_ptr][col-1];
            int64 mid = dp[prev_ptr][col];
            int64 right = dp[prev_ptr][col+1];

            dp[cur_ptr][col] = min(left, min(mid, right)) + cur_val;
            cur_val = ((cur_val+1LL))>max_val?1LL:cur_val+1LL;
        }

        cur_ptr = prev_ptr;
    }

    int64 ret = INF;

    for (int col = 1; col <= col_size; ++col) {
        ret = min(ret, dp[(cur_ptr+1)%2][col]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int R, C, M;
    cin >> R >> C >> M;
    cout << simulate(R, C, (int64)M) << '\n';

    return 0;
}