#include <iostream>
#include <queue>

using namespace std;

void input(int& L, int& K, priority_queue<int>& rq) {
    int N;

    for (cin >> N >> L >> K; N > 0; --N) {
        int R;
        cin >> R;
        rq.push(-R);
    }
}

int simulate(int L, int K, priority_queue<int>& rq) {
    int ret = 0;

    for (; !rq.empty(); rq.pop()) {
        int cur_resistance = -rq.top();

        if (cur_resistance > L) {
            break;
        }

        L += K, ++ret;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L, K;
    priority_queue<int> resistance_pq;

    input(L, K, resistance_pq);
    cout << simulate(L, K, resistance_pq) << '\n';

    return 0;
}