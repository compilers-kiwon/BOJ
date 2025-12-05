#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

typedef pair<int, int> Problem; // <day, cost>

int N, T, dp[MAX_SIZE][MAX_SIZE];
Problem p[MAX_SIZE];

int input(void) {
    int ret = 0;

    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> p[i].first >> p[i].second;
        ret += p[i].second;
    }

    return ret;
}

int simulate(void) {
    for (int cur_problem = 1; cur_problem <= N; cur_problem++) {
        int cur_day = p[cur_problem].first;
        int cur_penalty = p[cur_problem].second;

        dp[cur_problem][cur_day] = cur_penalty;

        for (int prev_day = 1; prev_day <= T; prev_day++) {
            dp[cur_problem][prev_day] =
                max(dp[cur_problem][prev_day], dp[cur_problem-1][prev_day]);
            
            if ((cur_day + prev_day) <= T) {
                dp[cur_problem][cur_day+prev_day] =
                    max(dp[cur_problem][cur_day+prev_day], dp[cur_problem-1][prev_day] + cur_penalty);
            }
        }
    }

    int ret = 0;

    for (int i = 1; i <= T; i++) {
        ret = max(ret, dp[N][i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total_penalty = input();
    cout << total_penalty - simulate() << '\n';

    return 0;
}