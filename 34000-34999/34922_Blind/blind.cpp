#include <iostream>

using namespace std;

const double PI = 3.141592f;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double w, h, r, b;
    cin >> w >> h >> r;

    b = (w * h) - (r * r * PI / 4.0f);
    cout << fixed; cout.precision(2);
    cout << b << '\n';

    return 0;
}