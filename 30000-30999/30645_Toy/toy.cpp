#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000)

int R, C, N, state[MAX_SIZE];

void input(priority_queue<int>& toys) {
    cin >> R >> C >> N;

    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        toys.push(-h);
    }
}

int simulate(priority_queue<int>& toys) {
    int ret = 0;

    for (int col = 0; !toys.empty(); toys.pop()) {
        int cur_toy = -toys.top();

        if (cur_toy <= state[col]) {
            continue;
        }

        state[col] = cur_toy;
        col = (col + 1) % C;
        ret++;
    }

    return min(ret, R * C);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> toys;

    input(toys);
    cout << simulate(toys) << '\n';

    return 0;
}