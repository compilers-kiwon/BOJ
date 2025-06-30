#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)
#define TBD (-1)

#define ATTACKED (0)
#define UNATTACKED (1)
#define MAX_STATE (2)

typedef long long int int64;

int N;
int64 R[MAX_SIZE], dp[MAX_STATE][MAX_SIZE];

int64 get_dp(int idx, int state) {
    int64& ret = dp[state][idx];

    if (ret != TBD) {
        return ret;
    }

    if (state == ATTACKED) {
        ret = min(get_dp(idx - 1, ATTACKED), get_dp(idx - 1, UNATTACKED)) + R[idx];
    } else {
        ret = get_dp(idx - 1, ATTACKED);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for (int i = 1; i <= N; i++) {
        cin>>R[i];
        dp[ATTACKED][i] = dp[UNATTACKED][i] = TBD;
    }

    dp[ATTACKED][1] = R[1];
    dp[UNATTACKED][1] = 0;

    cout<<min(get_dp(N, ATTACKED), get_dp(N, UNATTACKED))<<'\n';

    return 0;
}