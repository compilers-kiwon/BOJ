#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        double p1, p2, d;

        cin >> p1 >> p2;
        d = abs(p1 - p2);

        cout << fixed; cout.precision(1);
        cout << d << '\n';
    }

    return 0;
}