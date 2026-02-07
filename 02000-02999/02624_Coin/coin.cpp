#include <iostream>

using namespace std;

#define MAX_VALUE (10000+1)
#define MAX_NUM_OF_COINS (100+1)

typedef pair<int, int> Coin; // <value, num>

int T, k, dp[MAX_VALUE], buf[MAX_VALUE];
Coin c[MAX_NUM_OF_COINS];

void input(void) {
    cin >> T >> k;

    for (int i = 1; i <= k; ++i) {
        cin >> c[i].first >> c[i].second;
    }
}

int simulate(void) {
    for (int i = 1; i <= k; ++i) {
        fill(&buf[1], &buf[T+1], 0);

        int value_of_coin = c[i].first;
        int num_of_coin = c[i].second;

        for (int used = 1; used <= num_of_coin; ++used) {
            int cur_value = used * value_of_coin;

            if (cur_value > T) {
                break;
            }

            buf[cur_value] += 1;
            
            for (int v = 1; v + cur_value <= T; ++v) {
                buf[v+cur_value] += dp[v];
            }
        }

        for (int v = 1; v <= T; ++v) {
            dp[v] += buf[v];
        }
    }

    return dp[T];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}