#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (500+1)
#define INF (0x7FFFFFFF)

int N, M, t[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

int get_dp(int cur_round, int cur_weapon) {
    int& ret = dp[cur_round][cur_weapon];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;

    for (int prev_weapon = 1; prev_weapon <= M; ++ prev_weapon) {
        if (prev_weapon == cur_weapon) {
            continue;
        }

        ret = min(ret, get_dp(cur_round - 1, prev_weapon) + t[cur_round][cur_weapon]);
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> t[i][j], dp[i][j] = TBD;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_time = INF;

    input();

    for (int w = 1; w <= M; w++) {
        min_time = min(min_time, get_dp(N, w));
    }

    cout << min_time << '\n';

    return 0;
}