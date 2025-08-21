#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_DIST (1000000+1)

int N, L, P, station[MAX_DIST];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        station[a] = b;
    }

    cin >> L >> P;
}

int simulate(void) {
    int ret = 0;
    priority_queue<int> oil_q;

    for (int cur_pos = 0, cur_oil = P; cur_pos < L; cur_pos++, cur_oil--) {
        if (station[cur_pos] != 0) {
            oil_q.push(station[cur_pos]);
        }

        if (cur_oil == 0) {
            if (oil_q.empty()) {
                return -1;
            }

            cur_oil += oil_q.top();
            oil_q.pop();
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans;

    input();
    cout << simulate() << '\n';

    return 0;
}