#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double A, B, M;

    cin >> A >> B;
    M = (B - A) / 400.0f;

    cout << fixed; cout.precision(4);
    cout << 1.0f / (1.0f + pow(10, M)) << '\n';

    return 0;
}