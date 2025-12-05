#include <iostream>
#include <vector>

using namespace std;

#define NONE (-1)
#define MAX_COINS (1000+1)
#define MAX_SIZE (50000+1)

#define POSSIBLE (1)
#define IMPOSSIBLE (0)

bool dp[MAX_COINS][MAX_SIZE];

int input(vector<int>& m) {
    int N, sum;

    if (!(cin >> N)) {
        return NONE;
    }

    sum = 0, m.push_back(0);

    for (int i = 1; i <= N; i++) {
        int val, num;

        cin >> val >> num;
        sum += val * num;

        for (int n = 1; num > 0; n <<= 1) {
            int c = min(num, n);
            m.push_back(c * val);
            num -= n;
        }
    }

    return sum;
}

int simulate(const vector<int>& coins, int half_val) {
    for (int i = 1; i < coins.size(); i++) {
        fill(&dp[i][1], &dp[i][half_val+1], false);

        int cur_val = coins[i];

        if (cur_val <= half_val) {
            dp[i][cur_val] = true;
        }

        for (int prev_val = 1; prev_val <= half_val; prev_val++) {
            dp[i][prev_val] |= dp[i-1][prev_val];

            if ((prev_val + cur_val) <= half_val) {
                dp[i][prev_val+cur_val] |= dp[i-1][prev_val];
            }
        }

        if (dp[i][half_val] == true) {
            return POSSIBLE;
        }
    }

    return IMPOSSIBLE;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int total;
        vector<int> coins;

        total = input(coins);

        if (total == NONE) {
            break;
        }

        if ((total % 2) != 0) {
            cout << "0\n";
            continue;
        }

        cout << simulate(coins, total / 2) << '\n';
    }

    return 0;
}