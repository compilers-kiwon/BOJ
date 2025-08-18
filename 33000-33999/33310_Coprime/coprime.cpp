#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int l, r;

        cin >> l >> r;

        if (l == 1 && r == 1) {
            cout << "1\n";
        } else {
            cout << r - l << '\n';
        }
    }

    return 0;
}