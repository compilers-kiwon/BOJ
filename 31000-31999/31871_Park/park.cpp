#include <iostream>

using namespace std;

#define NUM_OF_RIDES (9)

int N, M, connected[NUM_OF_RIDES+1][NUM_OF_RIDES+1], all_visited;

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int u, v, d;

        cin >> u >> v >> d;

        if (connected[u][v] == 0 || d > connected[u][v]) {
            connected[u][v] = d;
        }
    }

    all_visited = (1 << (N +1)) - 1;
}

void dfs(int cur, int sum, int visited, int& max_sum) {
    if (visited == all_visited) {
        max_sum = max(max_sum, sum);
        return;
    }

    // Gate, exception case
    if ((visited + 1) == all_visited && connected[cur][0] != 0) {
        dfs(0, sum + connected[cur][0], visited | (1 << 0), max_sum);
    }

    for (int i = 1; i <= N; i++) {
        if (connected[cur][i] != 0 && (visited & (1 << i)) == 0) {
            dfs(i, sum + connected[cur][i], visited | (1 << i), max_sum);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_dist = 0;

    input();
    dfs(0, 0, 0, max_dist);

    cout << ((max_dist==0)?-1:max_dist) << '\n';

    return 0;
}