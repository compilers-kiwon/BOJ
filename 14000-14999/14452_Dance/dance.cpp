#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (10000+1)

int N, T_max, d[MAX_SIZE];

int simulate(int max_size) {
    int cur_time, i;
    priority_queue<int> pq;

    for (i = 1; i <= N && pq.size() < max_size; i++) {
        pq.push(-d[i]);
    }

    for (; i <= N; i++, pq.pop()) {
        int cur_time = -pq.top();
        pq.push(-(cur_time + d[i]));
    }

    for (; !pq.empty(); pq.pop()) {
        cur_time = -pq.top();
    }

    return cur_time;
}

int bin_search(int lo, int hi) {
    int ret;

    for (; (lo + 1) < hi;) {
        int mid = (lo + hi) / 2;
        int required_time = simulate(mid);

        if (required_time <= T_max) {
            ret = hi = mid;
        } else {
            lo = mid;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> T_max;
    
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }

    cout <<bin_search(1, N + 1) << '\n';

    return 0;
}