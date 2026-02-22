#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, b, c;

    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 2 << '\n';
    } else {
        int max_len = max(a, max(b, c));

        if ((a * a + b * b + c * c) == 2 * (max_len * max_len)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}