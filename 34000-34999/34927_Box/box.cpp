#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt, sum;
    priority_queue<int> pq;

    cin >> N, cnt = sum = 0;

    for (int i = 1; i <= N; i++) {
        int w;
        cin >> w;
        pq.push(-w);
    }

    for (; !pq.empty(); pq.pop()) {
        int cur_weight = -pq.top();

        if (cur_weight >= sum) {
            cnt++, sum += cur_weight;
        }
    }

    cout << cnt << '\n';

    return 0;
}