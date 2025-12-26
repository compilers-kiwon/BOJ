#include <iostream>
#include <cmath>

using namespace std;

void simulate(int head, int tail) {
    if (head == tail) {
        cout << head << '\n';
        return;
    }

    int dir = 1;
    int start = max(head, tail / 2);

    cout << dir * start << ' ';

    for (int i = tail; i >= head; i--) {
        if (i == start) {
            continue;
        }
        
        dir *= -1;
        cout << dir * i << ' ';
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int L, R;
        cin >> L >> R;
        simulate(L, R);
    }

    return 0;
}