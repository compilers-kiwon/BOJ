#include <iostream>

using namespace std;

#define MAX_SIZE (16+1)

int C, N, W[MAX_SIZE];

void input(void) {
    cin >> C >> N;

    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
}

void dfs(int cur_idx, int cur_sum, int& max_weight) {
    if (cur_sum > C) {
        return;
    }

    max_weight = max(max_weight, cur_sum);

    if (cur_idx > N) {
        return;
    }

    dfs(cur_idx + 1, cur_sum + W[cur_idx], max_weight);
    dfs(cur_idx + 1, cur_sum, max_weight);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_weight = 0;

    input();
    dfs(1, 0, max_weight);
    cout << max_weight << '\n';

    return 0;
}