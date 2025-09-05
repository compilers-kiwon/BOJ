#include <iostream>
#include <queue>

using namespace std;

int N, M;
priority_queue<int> cars, charger;

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        cars.push(t);
    }

    for (int i = 1; i <= M; i++) {
        charger.push(0);
    }
}

int simulate(void) {
    for (; !cars.empty(); cars.pop()) {
        int t = cars.top();
        int c = charger.top();

        charger.pop();
        charger.push(c - t);
    }

    for (; charger.size() != 1; charger.pop());
    return -(charger.top());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}