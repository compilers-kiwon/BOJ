#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double p, l;
    cin >> p >> l;

    cout << fixed; cout.precision(6);
    cout << 100.0 * l / (100.0 - l) << '\n';

    return 0;
}