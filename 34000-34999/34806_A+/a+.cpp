#include <iostream>

using namespace std;

#define MAX_SIZE (2500+1)

typedef pair<int, int> Problem;

int N, T, W;
int dp[MAX_SIZE][MAX_SIZE];
Problem p[MAX_SIZE];

void input(void) {
    cin >> N >> T >> W;

    for (int i = 1; i <= N; i++) {
        int& t = p[i].first;
        int& w = p[i].second;
        cin >> t >> w;
    }
}

int simulate(int x) {
    int ret = 0;
    int available_time = T - x;

    for (int i = 1; i <= N; i++) {
        int cur_time = max(p[i].first - x, 0);

        fill(&dp[i][0], &dp[i][available_time+1], 0);
        dp[i][cur_time] = p[i].second;

        for (int t = 0; t <= available_time; t++) {
            if (dp[i-1][t] == 0) {
                continue;
            }

            dp[i][t] = max(dp[i-1][t], dp[i][t]);

            if ((t + cur_time) <= available_time) {
                dp[i][t+cur_time] = max(dp[i-1][t] + p[i].second, dp[i][t+cur_time]);
            }
        }
    }

    for (int i = 0; i <= available_time; i++) {
        ret = max(ret, dp[N][i]);
    }

    return ret;
}

int bin_search(void) {
    int ret = T + 1;

    for (int lo = 0, hi = T; lo <= hi;) {
        int mid = (lo + hi) / 2;

        if (simulate(mid) >= W) {
            hi = mid - 1;
            ret = min(ret, mid);
        } else {
            lo = mid + 1;
        }
    }

    return ((ret==T+1)?-1:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << bin_search() << '\n';

    return 0;
}