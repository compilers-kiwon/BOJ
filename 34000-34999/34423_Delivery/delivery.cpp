#include <iostream>
#include <climits>

using namespace std;

#define MAX_SIZE (100+1)
#define NUM_OF_CITIES (3)
#define TBD (INT_MIN)

int N, cost_table[NUM_OF_CITIES+1][NUM_OF_CITIES+1];
int profit_table[NUM_OF_CITIES+1][MAX_SIZE];
int dp[NUM_OF_CITIES+1][MAX_SIZE];

void input(void) {
    const pair<int, int> path[NUM_OF_CITIES+1] = {
        {0, 0}, {1, 2}, {1, 3}, {3, 2}
    };

    for (int i = 1; i <= NUM_OF_CITIES; i++) {
        int c1 = path[i].first;
        int c2 = path[i].second;
        int cost_to_drive;

        cin >> cost_to_drive;
        cost_table[c1][c2] = cost_table[c2][c1] = cost_to_drive;
    }

    cin >> N;

    for (int i = 1; i <= NUM_OF_CITIES; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> profit_table[i][j];
            dp[i][j] = TBD;
        }
    }
}

int get_dp(int cur_city, int cur_day) {
    int& ret = dp[cur_city][cur_day];

    if (ret != TBD) {
        return ret;
    }

    for (int prev_city = 1; prev_city <= NUM_OF_CITIES; prev_city++) {
        int cost_to_drive = (cur_day==1)?0:cost_table[prev_city][cur_city];
        ret = max(ret, get_dp(prev_city, cur_day - 1) - cost_to_drive + profit_table[cur_city][cur_day]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_profit = TBD;

    input();

    for (int i = 1; i <= NUM_OF_CITIES; i++) {
        max_profit = max(max_profit, get_dp(i, N));
    }

    cout << max_profit << '\n';
    return 0;
}