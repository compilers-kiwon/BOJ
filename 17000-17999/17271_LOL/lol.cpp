#include <iostream>

using namespace std;

#define MAX_SIZE (10000+1)
#define TBD (-1)
#define MOD(n) ((n)%1000000007)

int dp[MAX_SIZE];

int get_dp(int cur_time, int a_time, int b_time) {
    if (cur_time == 0) {
        return 1;
    }

    if (cur_time < 0) {
        return 0;
    }

    int& ret = dp[cur_time];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;
    ret = MOD(ret + get_dp(cur_time - a_time, a_time, b_time));
    ret = MOD(ret + get_dp(cur_time - b_time, a_time, b_time));

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    fill(&dp[1], &dp[N+1], TBD);
    cout << get_dp(N, 1, M) << '\n';

    return 0;
}