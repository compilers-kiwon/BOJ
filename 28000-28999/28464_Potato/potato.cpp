#include <iostream>
#include <queue>
#include <deque>

using namespace std;

void input(deque<int>& dq) {
    int N;
    priority_queue<int> pq;

    for (cin >> N; N > 0; N--) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for (; !pq.empty(); pq.pop()) {
        dq.push_back(pq.top());
    }
}

pair<int, int> simulate(deque<int>& dq) {
    pair<int, int> ret = {0, 0};

    for (int i = 0; !dq.empty(); i++) {
        if (i % 2 == 0) {
            ret.second += dq.front();
            dq.pop_front();
        } else {
            ret.first += dq.back();
            dq.pop_back();
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    pair<int, int> potato;
    deque<int> a;

    input(a);
    potato = simulate(a);
    cout << potato.first << ' ' << potato.second << '\n';

    return 0;
}