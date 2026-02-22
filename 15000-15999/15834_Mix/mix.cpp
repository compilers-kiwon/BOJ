#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (76)

int get_dp(int n, int dp[]) {
    int& ret = dp[n];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    if (n - 2 > 0) {
        ret += get_dp(n - 2, dp);
    }

    if (n - 3 > 0) {
        ret += get_dp(n - 3, dp);
    }

    return ret;
}

void init(int dp[]) {
    fill(&dp[1], &dp[MAX_SIZE+1], TBD);
    dp[1] = dp[2] = 1;
    get_dp(MAX_SIZE, dp);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int dp[MAX_SIZE+1], i;

    for (init(dp), i = 1;;++i) {
        int n;
        
        cin >> n;

        if (n == 0) {
            break;
        }

        cout << "Case #" << i <<": ";
        
        if (n == 1 || n == 2) {
            cout << 0 <<'\n';
        } else if (n == 3) {
            cout << 1 << '\n';
        } else {
            cout << dp[n-1] + dp[n] << '\n';
        }
    }

    return 0;
}