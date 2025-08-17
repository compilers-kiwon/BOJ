#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int k, n;
    cin >> k >> n;
    cout << n + 1 << ' ' << (k * n) + 1 << '\n';

    return 0;
}