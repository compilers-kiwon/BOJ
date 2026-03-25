#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int int64;

#define TBD (-1)
#define TRUE (1)
#define FALSE (0)

#define INF (5000LL*1000000LL)

int get_dp(int64 pos, vector<int>& dp,
            const vector<int64>& A, int64 K) {
    int& ret = dp[pos];

    if (ret != TBD) {
        return ret;
    }

    ret = FALSE;

    for (int64 i = pos - 1LL; i >= max(1LL, pos - K); --i) {
        int64 required = (pos - i) * (1LL + abs(A[i] - A[pos]));

        if (required <= K && get_dp(i, dp, A, K) == TRUE) {
            ret = TRUE;
            break;
        }
    }

    return ret;
}

int64 bin_search(int64 lo, int64 hi,
                    const vector<int64>& A, int size) {
    int64 ret;

    for (; lo <= hi;) {
        int64 mid = (lo + hi) / 2;
        vector<int> dp(size + 1, TBD);

        dp[1] = TRUE;

        if (get_dp(size, dp, A, mid) == TRUE) {
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int64> A(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    cout << bin_search(1LL, INF, A, N) << '\n';
    return 0;
}