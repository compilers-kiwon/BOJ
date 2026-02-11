#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const double c4 = 0.229 * 0.324;
    const double a3 = 0.297 * 0.420;
    const double a4 = 0.210 * 0.297;

    double c4w, a3w, a4w;
    cin >> c4w >> a3w >> a4w;
    
    cout << fixed; cout.precision(6);
    cout << (2.0 * c4w * c4) + (2.0 * a3w * a3) + (a4w * a4) << '\n';

    return 0;
}