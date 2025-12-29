#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE (100+1)
#define MAX_BAG_VOL (1000000+1)

#define TRUE (1)
#define FALSE (0)

int N, W[MAX_SIZE], V[MAX_SIZE];
int M, K[MAX_SIZE], sum_of_value[MAX_BAG_VOL], tmp[MAX_BAG_VOL];
char used[MAX_BAG_VOL][MAX_SIZE];

int input(void) {
    int max_weight = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> K[i];
        max_weight = max(max_weight, K[i]);
    }

    return max_weight;
}

int simulate(int max_weight) {
    for (int i = 1; i <= N; i++) {
        int cur_weight = W[i];
        int cur_value = V[i];
        
        for (int prev_weight = 0; prev_weight <= max_weight; prev_weight++) {
            if (prev_weight + cur_weight <= max_weight) {
                tmp[prev_weight+cur_weight] =
                    max(tmp[prev_weight+cur_weight], sum_of_value[prev_weight] + cur_value);
            }
        }

        for (int weight = 0; weight <= max_weight; weight++) {
            sum_of_value[weight] = max(sum_of_value[weight], tmp[weight]);
            tmp[weight] = 0;
        }
    }

    int ret;
    double best = -1.0f;

    for (int i = 1; i <= M; i++) {
        for (int weight = 1; weight <= K[i]; weight++) {
            double cur = (double)sum_of_value[weight] / (double)K[i];

            if (best < cur) {
                best = cur, ret = i;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_available_weight = input();
    cout << simulate(max_available_weight) << '\n';

    return 0;
}