#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_SIZE (3000+1)

typedef pair<int, int> State; // <X, T>

int N, X[MAX_SIZE], T[MAX_SIZE];
priority_queue<State> pq;

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }

    for (int i = 1; i <= N; i++) {
        pq.push({X[i], T[i]});
    }

    pq.push({0, 0});
}

int simulate(void) {
    int cur_time, cur_pos;

    for (cur_time = cur_pos = 0; !pq.empty(); pq.pop()) {
        int next_return_pos = pq.top().first;
        int next_return_time = pq.top().second;
        int arrival_time = abs(cur_pos - next_return_pos) + cur_time;

        cur_time = max(next_return_time, arrival_time);
        cur_pos = next_return_pos;
    }

    return cur_time;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}