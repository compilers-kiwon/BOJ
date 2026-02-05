#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, R;
    cin >> N >> R;
    cout << N + (2 * R) - 1 << '\n';

    return 0;
}