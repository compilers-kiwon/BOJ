#include <iostream>
#include <vector>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (20+1)
#define MAX_BUDGET (300+1)

int N, M, profit[MAX_SIZE][MAX_BUDGET];
int dp[MAX_SIZE][MAX_BUDGET][MAX_BUDGET];

int get_dp(int cur_company, int used_amount, int cur_amount) {
    int& ret = dp[cur_company][used_amount][cur_amount];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int amount = 0; amount <= (used_amount - cur_amount); amount++) {
        int prev_company = cur_company - 1;
        int prev_used_amount = used_amount - cur_amount;
        ret = max(ret, get_dp(prev_company, prev_used_amount, amount));
    }

    return (ret += profit[cur_company][cur_amount]);
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int a;

        cin >> a;

        for (int j = 1; j <= M; j++) {
            cin >> profit[j][a];
            fill(&dp[j][i][0], &dp[j][i][N+1], TBD);
        }
    }
}

void backtrace(int cur_company, int total_money,
                int target_profit, vector<int>& amount) {
    if (cur_company == 0) {
        return;
    }

    for (int a = 0; a <= total_money; a++) {
        if (dp[cur_company][total_money][a] == target_profit) {
            total_money -= a;
            target_profit -= profit[cur_company][a];
            
            amount.push_back(a);
            break;
        }
    }
    backtrace(cur_company - 1, total_money, target_profit, amount);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_profit = 0;
    vector<int> amount;

    input();

    for (int a = 0; a <= N; a++) {
        max_profit = max(max_profit, get_dp(M, N, a));
    }

    cout << max_profit << '\n';

    backtrace(M, N, max_profit, amount);

    for (int i = M - 1; i >= 0; i--) {
        cout << amount[i] << ((i==0)?'\n':' ');
    }

    return 0;
}