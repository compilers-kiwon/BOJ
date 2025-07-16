#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (100000+1)
#define MOD(n) ((n)%1000000009)
#define TBD (-1)

int get_dp(int cur_target, vector<int>& dp) {
    if (cur_target < 0) {
        return 0;
    }

    int& ret = dp[cur_target];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int i = 1; i <= 3; i++) {
        ret = MOD(ret + get_dp(cur_target - (i * 2), dp));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    vector<int> dp(MAX_NUM, TBD);
    
    cin >> T;

    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 2;
    dp[4] = 3;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << get_dp(n, dp) <<'\n';
    }

    return 0;
}