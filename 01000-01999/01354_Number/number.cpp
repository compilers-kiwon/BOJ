#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long int int64;

int64 N, P, Q, X, Y;
unordered_map<int64, int64> dp;

int64 get_dp(int64 i) {
    if (i <= 0) {
        return 1;
    }

    auto it = dp.find(i);

    if (it != dp.end()) {
        return it->second;
    }

    int64 ret = get_dp(floor(i / P) - X) + get_dp(floor(i / Q) - Y);

    dp[i] = ret;
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> P >> Q >> X >> Y;
    cout << get_dp(N) << '\n';

    return 0;
}