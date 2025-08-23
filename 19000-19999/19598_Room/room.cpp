#include <iostream>
#include <queue>

using namespace std;

enum {
    END = 1,
    START = 0,
};

typedef pair<int, int> Event; // <-time, start(true)/end(false)>

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, available, required;
    priority_queue<Event> pq;

    for (cin >> N; N > 0; N--) {
        int start, end;
        cin >> start >> end;
        pq.push({-start, START}), pq.push({-end, END});
    }

    for (available = required = 0; !pq.empty(); pq.pop()) {
        if (pq.top().second == START) {
            if (available == 0) {
                required++;
            } else {
                available--;
            }
        } else {
            available++;
        }
    }

    cout << required << '\n';
    return 0;
}