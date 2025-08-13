#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

typedef long long int int64;

int N;
int64 grid[MAX_SIZE][MAX_SIZE], max_num, sum;

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> grid[row][col];
            sum += grid[row][col];
            max_num = max(max_num, grid[row][col]);
        }
    }
}

bool check_condition(int64 air) {
    int64 cur = 0;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cur += min(air, grid[row][col]);
        }
    }

    return ((2 * cur) >= sum);
}

int64 simulate(void) {
    int64 ret = max_num;

    for (int64 lo = 0, hi = max_num + 1; (lo + 1) < hi;) {
        int64 mid = (lo + hi) / 2;

        if (check_condition(mid) == true) {
            ret = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}