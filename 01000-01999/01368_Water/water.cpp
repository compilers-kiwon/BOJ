#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (300+1)

int N, W[MAX_SIZE], grid[MAX_SIZE][MAX_SIZE];
int total_cost, water_source[MAX_SIZE];

typedef pair<int, pair<int, int>> Path;

void input(priority_queue<Path>& pq) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        total_cost += W[i], water_source[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            pq.push({-grid[i][j], {i, j}});
        }
    }
}

int find_source(int cur) {
    int& ret = water_source[cur];

    if (cur != ret) {
        ret = find_source(ret);
    }

    return ret;
}

void simulate(priority_queue<Path>& pq) {
    for (; !pq.empty(); pq.pop()) {
        int cost = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        int i_source = find_source(i);
        int j_source = find_source(j);

        if (i_source == j_source) {
            continue;
        }
        
        int expensive_pos, cheap_pos;
        
        if (W[i_source] < W[j_source]) {
            expensive_pos = j_source, cheap_pos = i_source;
        } else {
            expensive_pos = i_source, cheap_pos = j_source;
        }

        if (cost >= W[expensive_pos]) {
            continue;
        }

        water_source[expensive_pos] = cheap_pos;
        total_cost -= W[expensive_pos] - cost;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<Path> pq;

    input(pq);
    simulate(pq);
    cout << total_cost << '\n';

    return 0;
}