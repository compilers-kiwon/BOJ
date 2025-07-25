#include <iostream>

using namespace std;

#define MAX_NUM (8)
#define MAX_SIZE (100000+1)

int N, f[MAX_NUM+1], dp[MAX_SIZE];

void init(void) {
    f[0] = 1;

    for (int i = 1; i <= MAX_NUM; i++) {
        f[i] = f[i-1] * i;
        dp[f[i]] = 1;
    }
}

int get_dp(int num) {
    int& ret = dp[num];

    if (ret != 0) {
        return ret;
    }

    ret = 1000000;

    for (int i = 1; i <= MAX_NUM; i++) {
        if ((num - f[i]) > 0) {
            ret = min(ret, get_dp(num - f[i]) + 1);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;
    init();
    cout << get_dp(N) << '\n';

    return 0;
}