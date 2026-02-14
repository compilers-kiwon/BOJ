#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, sum;

    cin >> N; sum = N - 1LL;

    for (int i = 2; i < N; ++i) {
        sum += (N - i) * 2LL;
    }

    cout << sum << '\n';

    for (int i = 2; i <= N; ++i) {
        cout << 1 << ' ' << i << '\n';
    }

    return 0;
}