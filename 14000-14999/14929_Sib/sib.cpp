#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

typedef long long int int64;

int n;
int64 x[MAX_SIZE], sum[MAX_SIZE];

void input(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum[i] = sum[i-1] + x[i];
    }
}

int64 solve(void) {
    int64 ret = 0;

    for (int i = 1; i <= n; i++) {
        ret += x[i] * sum[i-1];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << solve() << '\n';

    return 0;
}