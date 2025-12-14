#include <iostream>

using namespace std;

#define TBD (-1LL)
#define NONE (-1)
#define MAX_SIZE (200000+1)
#define INF (1000000000000000LL+1LL)

typedef long long int int64;

int N, P[MAX_SIZE];
int64 X, A[MAX_SIZE], dp[MAX_SIZE];

void input(void) {
    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], dp[i] = TBD;
    }

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
}

int64 get_dp(int n) {
    int64& ret = dp[n];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;

    if (P[n] == NONE) {
        ret = A[n];
    } else {
        ret = min(ret, get_dp(P[n]) + A[n]);
    }

    return ret;
}

int find_max_ball(void) {
    int ret = NONE;

    for (int i = N; i >= 1; i--) {
        if (get_dp(i) <= X) {
            ret = i;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << find_max_ball() << '\n';

    return 0;
}