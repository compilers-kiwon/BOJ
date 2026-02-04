#include <iostream>
#include <vector>

using namespace std;

const int TBD = -1;

int get_dp(int A, int B, vector<vector<int>>& dp) {
    int& ret = dp[A][B];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    if (A - 1 >= 0) {
        ret += get_dp(A - 1, B, dp);
    }

    if (B - 1 >= 0) {
        ret += get_dp(A, B - 1, dp);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int A, B, C, w;

        cin >> A >> B;

        if (A == -1 && B == -1) {
            break;
        }

        vector<vector<int>> dp(A + 1, vector<int>(B + 1, TBD));

        dp[0][0] = 1, C = A + B;
        w = get_dp(A, B, dp);
        cout << A << '+' << B << ((w==C)?"=":"!=") << C << '\n';
    }

    return 0;
}