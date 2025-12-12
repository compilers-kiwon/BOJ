#include <iostream>
#include <algorithm>

using namespace std;

#define LOWER (-1000000000)
#define UPPER (1000000000)

#define MAX_SIZE (200000+1)

typedef pair<int, int> Bomb;

int N, B;
Bomb b[MAX_SIZE+1];

bool simulate(int R) {
    int sum, min_cost;

    sum = min_cost = 0;

    for (int i = 1; i <= N + 1; i++) {
        int prev_pos = b[i-1].first;
        int cur_pos = b[i].first;

        if (cur_pos - prev_pos > R) {
            sum += min_cost;
            min_cost = b[i].second;
        } else {
            min_cost = min(min_cost, b[i].second);
        }
    }

    return (sum <= B);
}

int bin_search(int lo, int hi) {
    int ret;

    for (; lo <= hi;) {
        int mid = (lo + hi) / 2;

        if (simulate(mid) == true) {
            ret = mid, hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> b[i].first;
    }

    for (int i = 1; i <= N; i++) {
        cin >> b[i].second;
    }

    cin >> B;

    sort(&b[1], &b[N+1]);
    b[0] = {LOWER, 0}, b[N+1] = {UPPER, 0};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << bin_search(1, b[N].first - b[1].first) << '\n';

    return 0;
}