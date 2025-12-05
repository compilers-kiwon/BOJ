#include <iostream>
#include <string>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (5000)
#define MAX_SERVICE_DAYS (641)

string S;
int N, dp[MAX_SIZE];

int get_dp(int cur_pos) {
    if (cur_pos == -1) {
        return 0;
    }

    int& ret = dp[cur_pos];

    if (ret != TBD) {
        return ret;
    }

    ret = MAX_SIZE;

    for (int length = 1; length <= 3; length++) {
        int start = max(0, cur_pos - length + 1);

        if (S[start] == '0') {
            continue;
        }
        
        string sub = S.substr(start, length);
        int cur_service_days = stoi(sub);

        if (cur_service_days > MAX_SERVICE_DAYS) {
            break;
        }

        ret = min(ret, get_dp(start - 1) + 1);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> S;
    fill(&dp[0], &dp[N], TBD);
    cout << get_dp(N - 1) << '\n';

    return 0;
}