#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

int N, M, required[MAX_SIZE];

int simulate(int m) {
    int ret = 1;
    int cur = m;

    for (int i = 1; i <= N; ++i) {
        if (cur < required[i]) {
            ++ret, cur = m;
        }

        cur -= required[i];
    }

    return ret;
}

int bin_search(int lo, int upper, int hi) {
    for (; lo <= hi;) {
        int mid = (lo + hi) / 2;
        int cnt = simulate(mid);

        if (cnt > M || mid < upper) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}

int input(int& min_required, int& max_required) {
    int ret = 0;

    min_required = MAX_SIZE;
    max_required = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> required[i];
        ret += required[i];
        min_required = min(min_required, required[i]);
        max_required = max(max_required, required[i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int lo, hi, sum;

    sum = input(lo, hi);
    cout << bin_search(lo, hi, sum) << '\n';

    return 0;
}