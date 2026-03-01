#include <iostream>
#include <queue>

using namespace std;

#define NUM_OF_VOTES (5)
#define COMPETITION_RATE (1000)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> pq;

    for (int i = 1; i <= NUM_OF_VOTES; ++i) {
        int v;
        cin >> v;
        pq.push(v);
    }

    int _16th, cnt;

    _16th = pq.top(); pq.pop();
    for (cnt = 0; !pq.empty() && (_16th - pq.top()) <= COMPETITION_RATE; pq.pop(), ++cnt) {}
    cout << cnt << '\n';

    return 0;
}