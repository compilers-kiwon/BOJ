#include <iostream>
#include <cmath>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 X, Y, W, S, t;

    cin >> X >> Y >> W >> S;

    if (2 * W <= S) {
        t = (X + Y) * W;
    } else {
        t = min(X, Y) * S;

        if (abs(X - Y) % 2LL == 0LL) {
            t += min(abs(X - Y) * W, abs(X - Y) * S);
        } else {
            t += min(abs(X - Y) * W, (abs(X - Y) - 1) * S + W);
        }
    }

    cout << t << '\n';

    return 0;
}