#include <iostream>

using namespace std;

#define TBD (-1)
#define INF (1000000)
#define MAX_SIZE (100000+1)

int N, M, A, B, dp[MAX_SIZE];

int get_dp(int cur) {
    if (cur <= 0) {
        return ((cur==0)?0:INF);
    }

    int& ret = dp[cur];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;
    ret = min(ret, get_dp(cur - A) + 1);
    ret = min(ret, get_dp(cur - B) + 1);

    return ret;
}

void input(void) {
    cin >> N >> M >> A >> B;
    fill(dp, dp + MAX_SIZE, TBD);

    for (int i = 1; i <= M; ++i) {
        int L, R;

        for (cin >> L >> R; L <= R; ++L) {
            dp[L] = INF;
        }
    }
}

int simulate(void) {
    int ret = get_dp(N);
    return ((ret==INF)?-1:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}