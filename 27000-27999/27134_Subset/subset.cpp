#include <iostream>

using namespace std;

#define MAX_NUM (39)
#define MAX_SUM (MAX_NUM*(MAX_NUM+1)/4)

typedef long long int int64;

int N;
int64 dp[MAX_NUM+1][MAX_SUM+1];

int64 simulate(int max_sum) {
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1LL;

        for (int s = 1; s <= max_sum; s++) {
            if (dp[i-1][s] != 0LL) {
                dp[i][s] += dp[i-1][s];

                if (s + i <= max_sum) {
                    dp[i][s+i] += dp[i-1][s];
                }
            }
        }
    }

    return (dp[N][max_sum] / 2LL);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin >> N;
    t = N * (N + 1) / 2;

    if (t % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    cout << simulate(t / 2) << '\n';

    return 0;
}