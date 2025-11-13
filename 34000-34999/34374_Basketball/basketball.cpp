#include <iostream>

using namespace std;

#define TBD (-1.0f)
#define MAX_SIZE (100+1)

int N, A2, A3, M2, M3, C2, C3;
double dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];
double a2p, a3p;

double get_dp(int attempt, int _2p, int _3p) {
    if (attempt > N) {
        return 0.0f;
    }

    double& ret = dp[attempt][_2p][_3p];

    if (ret != TBD) {
        return ret;
    }

    double m2p = (double)_2p / 100.0f;
    double m3p = (double)_3p / 100.0f;
    double succ_points, fail_points;

    ret = 0.0;

    int _2p_succ = min(_2p + C2, 100);
    int _2p_fail = max(_2p - C2, 0);

    succ_points = m2p * (2.0f + get_dp(attempt + 1, _2p_succ, _3p));
    fail_points = (1.0f - m2p) * get_dp(attempt + 1, _2p_fail, _3p);
    ret += a2p * (succ_points + fail_points);

    int _3p_succ = min(_3p + C3, 100);
    int _3p_fail = max(_3p - C3, 0);

    succ_points = m3p * (3.0f + get_dp(attempt + 1, _2p, _3p_succ));
    fail_points = (1.0f - m3p) * get_dp(attempt + 1, _2p, _3p_fail);
    ret += a3p * (succ_points + fail_points);

    ret += (1.0f - a2p - a3p) * get_dp(attempt + 1, _2p, _3p);

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> A2 >> A3 >>
        M2 >> M3 >> C2 >> C3;

    for (int a = 1; a <= N; a++) {
        for (int p2 = 0; p2 <= 100; p2++) {
            fill(&dp[a][p2][0], &dp[a][p2][MAX_SIZE], TBD);
        }
    }

    a2p = (double)A2/100.0f, a3p = (double)A3/100.0f;

    cout << fixed; cout.precision(8);
    cout << get_dp(1, M2, M3) << '\n';

    return 0;
}