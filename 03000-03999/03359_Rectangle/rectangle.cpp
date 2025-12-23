#include <iostream>
#include <cmath>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (1000+1)

int n, dp[MAX_SIZE][2];
int a[MAX_SIZE], b[MAX_SIZE];

void input(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        dp[i][0] = dp[i][1] = TBD;
    }

    dp[1][0] = a[1], dp[1][1] = b[1];
}

int get_dp(int idx, int state) {
    int& ret = dp[idx][state];

    if (ret != TBD) {
        return ret;
    }

    if (state == 0) {
        ret = max(get_dp(idx - 1, 0) + a[idx] + abs(b[idx] - b[idx-1]),
                    get_dp(idx - 1, 1) + a[idx] + abs(b[idx] - a[idx-1]));
    } else {
        ret = max(get_dp(idx - 1, 0) + b[idx] + abs(a[idx] - b[idx-1]),
                    get_dp(idx - 1, 1) + b[idx] + abs(a[idx] - a[idx-1]));
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << max(get_dp(n, 0), get_dp(n, 1)) << '\n';

    return 0;
}