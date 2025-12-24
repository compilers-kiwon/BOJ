#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, T;
    cin >> A >> T;
    cout << max(0, 10 + 2 * (25 - A + T)) << '\n';

    return 0;
}