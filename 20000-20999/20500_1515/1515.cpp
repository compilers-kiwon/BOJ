#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (1515+1)
#define MOD(n) ((n)%1000000007)

int N, dp[MAX_SIZE][3];

int get_dp(int digit_pos, int m) {
    if (digit_pos == 0) {
        return ((m==0)?1:0);
    }

    int& ret = dp[digit_pos][m];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int i = 1; i <= 2; i++) {
        ret = MOD(ret + get_dp(digit_pos - 1, (m + i) % 3));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    if (N == 1) {
        cout << "0\n";
        return 0;
    }

    fill(&dp[0][0], &dp[0][0] + (MAX_SIZE * 3), TBD);
    cout << get_dp(N - 1, 1) << '\n';

    return 0;
}