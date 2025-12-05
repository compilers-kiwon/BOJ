#include <iostream>

using namespace std;

#define MAX_SIZE (3000+1)
#define MAX_WEIGHT (10000+1)

typedef pair<int, int> Item;

int N, M, num_of_items;
int dp[MAX_SIZE][MAX_WEIGHT];
Item itm[MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int V, C, K;

        cin >> V >> C >> K;

        for (int n = 1; K > 0; n <<= 1) {
            int d = min(n, K);
            itm[++num_of_items] = {d * V, C * d};
            K -= d;
        }
    }
}

int simulate(void) {
    for (int i = 1; i <= num_of_items; i++) {
        int cur_weight = itm[i].first;
        int cur_satisfication = itm[i].second;

        dp[i][cur_weight] = cur_satisfication;

        for (int prev_weight = 1; prev_weight <= M; prev_weight++) {
            int prev_satisfication = dp[i-1][prev_weight];

            dp[i][prev_weight] = max(dp[i][prev_weight], prev_satisfication);

            if ((cur_weight + prev_weight) <= M) {
                dp[i][cur_weight+prev_weight] =
                    max(dp[i][cur_weight+prev_weight], prev_satisfication + cur_satisfication);
            }
        }
    }

    int ret = 0;

    for (int w = 1; w <= M; w++) {
        ret = max(ret, dp[num_of_items][w]);
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