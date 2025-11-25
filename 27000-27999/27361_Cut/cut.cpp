#include <iostream>
#include <vector>

using namespace std;

#define NONE (0x7FFFFFFFFFFFFFFF)

typedef long long int int64;

int64 calculate_cost(int64 a, int64 b, int64 L) {
    return ((L == 1)?0:((a * (L - 1) * (L - 1)) + b));
}

vector<int64> simulate(const vector<int64>& prev_cost, int cur_size,
                        int num_of_required_sticks, int64 a, int64 b) {
    int64 cut_cost = calculate_cost(a, b, cur_size);
    vector<int64> cur_cost(num_of_required_sticks + 1, NONE);

    cur_cost[min(cur_size, num_of_required_sticks)] = cut_cost;

    for (int i = 1; i <= num_of_required_sticks; i++) {
        if (prev_cost[i] == NONE) {
            continue;
        }

        cur_cost[i] = min(cur_cost[i], prev_cost[i]);

        int num_of_sticks = min(i + cur_size, num_of_required_sticks);

        cur_cost[num_of_sticks] = min(cur_cost[num_of_sticks],
                                        prev_cost[i] + cut_cost);

    }

    return cur_cost;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int N, K;
        int64 a, b;

        cin >> N >> K >> a >> b;

        vector<int> S(N + 1);
        vector<int64> cost_table(K + 1, NONE);

        for (int i = 1; i <= N; i++) {
            cin >> S[i];
        }

        for (int i = 1; i <= N; i++) {
            cost_table = simulate(cost_table, S[i], K, a, b);
        }

        cout << cost_table[K] << '\n';
    }

    return 0;
}