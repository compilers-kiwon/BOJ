#include <iostream>

using namespace std;

#define MAX_NUM_OF_STAGES (1000+1)
#define MAX_HP (100)

int N, K, s[MAX_NUM_OF_STAGES], h[MAX_NUM_OF_STAGES];
int dp[MAX_NUM_OF_STAGES][MAX_HP+1];

int simulate(void) {
    int ret = 0;
    
    for (int i = 1; i <= N; i++) {
        dp[i][MAX_HP-h[i]] = s[i];

        for (int hp = 0; hp <= MAX_HP; hp++) {
            int prev_score = dp[i-1][hp];
            int cur_hp = min(MAX_HP, hp + K);

            if (dp[i][cur_hp] < prev_score) {
                dp[i][cur_hp] = prev_score;
            }

            if (cur_hp >= h[i]) {
                dp[i][cur_hp-h[i]] = max(dp[i][cur_hp-h[i]], prev_score + s[i]);
            }
        }
    }

    for (int hp = 0; hp <= MAX_HP; hp++) {
        ret = max(ret, dp[N][hp]);
    }
    
    return ret;
}

void input(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}