#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define TBD (-1)
#define TRUE (1)
#define FALSE (0)

int get_dp(int pos, vector<int>& dp,
            const vector<int>& A, int K) {
    int& ret = dp[pos];

    if (ret != TBD) {
        return ret;
    }

    ret = FALSE;

    for (int i = pos - 1; i >= max(1, pos - K); --i) {
        int required = (pos - i) * (1 + abs(A[i] - A[pos]));

        if (required <= K && get_dp(i, dp, A, K) == TRUE) {
            ret = TRUE;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;

    cin >> N >> K;

    vector<int> A(N + 1);
    vector<int> dp(N + 1, TBD);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    dp[1] = TRUE;
    cout << ((get_dp(N, dp, A, K)==TRUE)?"YES":"NO") << '\n';

    return 0;
}