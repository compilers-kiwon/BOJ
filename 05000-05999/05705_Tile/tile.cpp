#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (40+1)

int dp[MAX_SIZE];

int get_dp(int pos) {
    if (pos < 0) {
        return 0;
    }

    int& ret = dp[pos];

    if (ret != TBD) {
        return ret;
    }

    return (ret = get_dp(pos - 1) + get_dp(pos - 2));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    dp[0] = 1;
    fill(&dp[1], &dp[MAX_SIZE], TBD);

    for (int N; cin >> N;) {
        if (N == 0) {
            break;
        }

        cout << get_dp(N) << '\n';
    }

    return 0;
}