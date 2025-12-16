#include <iostream>

using namespace std;

int simulate(int x, int n) {
    int ret;

    for (ret = 0; x < n; ret++) {
        int r = x % 3;

        switch (r) {
            case 0: x += 1; break;
            case 1: x *= 2; break;
            case 2: x *= 3; break;
            default:
                // do nothing
                break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, N;
    cin >> X >> N;
    cout << simulate(X, N) << '\n';

    return 0;
}