#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> State;

#define MAX_SIZE (250000+1)

int N, dp[MAX_SIZE+1];

int input(void) {
    cin >> N;
    fill(&dp[1], &dp[MAX_SIZE+1], MAX_SIZE);

    int X;

    for (int i = 1; i <= N; ++i) {
        cin >> X;
        dp[X] = 0;
    }

    return X;
}

int simulate(int last_pos) {
    int ret = MAX_SIZE;
    queue<State> q;

    for (q.push({0, 0}); !q.empty(); q.pop()) {
        int cur_pos = q.front().first;
        int cur_steps = q.front().second;

        if (cur_pos > last_pos) {
            ret = min(ret, cur_steps);
            continue;
        }

        for (int d = 2; d >= 1; --d) {
            int adj_pos = cur_pos + d;
            int adj_steps = cur_steps + 1;

            if (adj_steps < dp[adj_pos]) {
                dp[adj_pos] = adj_steps;
                q.push({adj_pos, adj_steps});
            }
        }
    }

    return ((ret==MAX_SIZE)?-1:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int last_pos = input();
    cout << simulate(last_pos) << '\n';

    return 0;
}