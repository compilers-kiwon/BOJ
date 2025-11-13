#include <iostream>
#include <vector>

using namespace std;

#define MAX_TIME (25)

typedef long long int int64;

bool simulate(int64 num_of_computers, int64 upper_time,
                const vector<int64>& time_to_flash) {
    int64 sum = 0;

    for (int i = 0; i < time_to_flash.size(); i++) {
        sum += upper_time / time_to_flash[i];
    }

    return (sum >= num_of_computers);
}

int64 solve(int64 num_of_computers,
                const vector<int64>& time_to_flash) {
    int64 ret;
    int64 lo = 1LL;
    int64 hi = (num_of_computers * (int64)MAX_TIME) + 1;

    for (; lo <= hi;) {
        int64 mid = (lo + hi) / 2;

        if (simulate(num_of_computers, mid, time_to_flash) == true) {
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, M;
    vector<int64> t;

    cin >> N >> M;

    for (int64 i = 0; i < M; i++) {
        int64 n;
        cin >> n;
        t.push_back(n);
    }

    cout << solve(N, t) << '\n';

    return 0;
}