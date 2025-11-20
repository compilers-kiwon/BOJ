#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (24)
#define INF (1000000+1)

int pizza[MAX_SIZE];

int input(void) {
    int n, c;

    fill(pizza, pizza + MAX_SIZE, INF);

    for (cin >> n >> c; n > 0; n--) {
        int t, p;
        cin >> t >> p;
        pizza[t] = min(pizza[t], p); 
    }

    return c;
}

int simulate(int capacity) {
    int ret = 0;
    priority_queue<int> pq;

    for (int t = 0; t < MAX_SIZE; t++) {
        pq.push(-pizza[t]);
    }

    for (; !pq.empty() && -pq.top() <= capacity; pq.pop(), ret++) {
        capacity += pq.top();
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int capacity = input();
    cout << simulate(capacity) << '\n';

    return 0;
}