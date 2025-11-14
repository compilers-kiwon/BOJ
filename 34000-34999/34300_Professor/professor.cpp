#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Shirt;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int C, cnt;
    priority_queue<Shirt> pq;

    for (cin >> C; C > 0; C--) {
        int S;
        cin >> S;
        pq.push({S, C});
    }

    for (cnt = 0; pq.size() >= 5; cnt++) {
        queue<Shirt> tmp;

        for (int i = 1; i <= 5; i++, pq.pop()) {
            Shirt s = pq.top();
            s.first--;
            tmp.push(s);
        }

        for (; !tmp.empty(); tmp.pop()) {
            if (tmp.front().first != 0) {
                pq.push(tmp.front());
            }
        }
    }

    cout << (cnt * 5) + pq.size() << '\n';
    return 0;
}