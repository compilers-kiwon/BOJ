#include <iostream>

using namespace std;

int simulate(int a, int b, int c) {
    int ret = 0;

    for (int x = 1; x <= a; x++) {
        for (int y = 1; y <= b; y++) {
            for (int z = 1; z <= c; z++) {
                if ((x % y) == (y % z) && (y % z) == (z % x)) {
                    ret++;
                }
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << simulate(a, b ,c) << '\n';
    }

    return 0;
}