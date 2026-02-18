#include <iostream>

using namespace std;

#define MAX_SIZE (100)
#define IMPOSSIBLE (-1)

int T, N, L[MAX_SIZE+1], R[MAX_SIZE+1];
bool dp[MAX_SIZE+1][MAX_SIZE+1][MAX_SIZE+1];

void input(void) {
    cin >> T >> N;

    for (int i = 1; i <= N; ++i) {
        int t;
        char c;

        cin >> t >> c;
        (c=='L')?++L[t]:++R[t];
    }
}

int simulate(void) {
    int max_possible_num = N / 2;

    dp[0][0][0] = true;

    for (int cur = 1; cur <= T; ++cur) {
        int prev = cur - 1;

        for (int prev_left = 0; prev_left <= max_possible_num; ++prev_left) {
            for (int prev_right = 0; prev_right <= max_possible_num; ++prev_right) {
                int prev_num_of_interviews = dp[prev][prev_left][prev_right];

                if (prev_num_of_interviews == false) {
                    continue;
                }

                for (int cur_left = 0; cur_left <= min(max_possible_num, L[cur]); ++cur_left) {
                    for (int cur_right = (cur_left==0)?1:0;
                            cur_right <= min(max_possible_num, R[cur]); ++cur_right) {
                        int left = prev_left + cur_left;
                        int right = prev_right + cur_right;

                        if (left > max_possible_num || right > max_possible_num) {
                            continue;
                        }

                        dp[cur][left][right] = true;
                    }
                }
            }
        }
    }

    int ret = IMPOSSIBLE;

    for (int n = (T + 1) / 2; n <= max_possible_num; ++n) {
        if (dp[T][n][n] == true) {
            ret = n + n;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}