#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_NUM_OF_COWS (100+1)

typedef pair<int, int> Stat;

int N;
Stat s[MAX_NUM_OF_COWS];
unordered_map<int, int> dp[MAX_NUM_OF_COWS];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> s[i].first >> s[i].second;
    }
}

int simulate(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        int cur_smartness = s[i].first;
        int cur_funness = s[i].second;

        dp[i][cur_smartness] = cur_funness;

        for (auto it = dp[i-1].begin(); it != dp[i-1].end(); it++) {
            int prev_smartness = it->first;
            int prev_funness = it->second;
            
            auto n = dp[i].find(prev_smartness);

            if (n == dp[i].end() || prev_funness > n->second) {
                dp[i][prev_smartness] = prev_funness;
            }

            int tf = prev_funness + cur_funness;
            int ts = prev_smartness + cur_smartness;
            auto m = dp[i].find(ts);

            if (m == dp[i].end() || tf > m->second) {
                dp[i][ts] = tf;
            }
        }
    }

    for (auto it = dp[N].begin(); it != dp[N].end(); it++) {
        if (it->first < 0 || it->second < 0) {
            continue;
        }

        ret = max(ret, it->first + it->second);
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