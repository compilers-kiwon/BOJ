#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (1000000+1)
#define MAX_TIME (1000000LL*1000000LL)

int N, M;
int64 A[MAX_SIZE];

bool simulate(int64 time) {
    int64 num_of_balloons = 0;

    for (int i = 1; i <= N; i++) {
        num_of_balloons += time / A[i];
    }

    return (num_of_balloons >= (int64)M);
}

int64 bin_search(int64 lo, int64 hi) {
    int64 ret;

    for (; lo <= hi;) {
        int64 mid = (lo + hi) / 2;

        if (simulate(mid) == true) {
            ret = mid, hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << bin_search(0, MAX_TIME) << '\n';

    return 0;
}