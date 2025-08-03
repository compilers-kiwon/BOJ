#include <iostream>

using namespace std;

#define MAX_NUM (1000)
#define TBD (-1)
#define MOD(n) ((n)%1000000009)

typedef long long int int64;

int64 dp[MAX_NUM+1][MAX_NUM+1];

int64 get_dp(int n, int m) {
    int64& ret = dp[n][m];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int64 d = 1; d <= 3; d++) {
        if ((n - d) > 0 && (m - 1) > 0) {
            ret = MOD(ret + get_dp(n - d, m - 1));
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i = 1; i <= MAX_NUM; i++) {
        fill(&dp[i][1], &dp[i][MAX_NUM+1], TBD);
    }

    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    dp[2][2] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    int T;

    for (cin >> T; T > 0; T--) {
        int n, m;
        cin >> n >> m;
        cout << get_dp(n, m) << '\n';
    }

    return 0;
}