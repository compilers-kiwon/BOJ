#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    double d1, d2, x;

    cin >> d1 >> d2 >> x;

    if (d1 < d2) {
        swap(d1, d2);
    }

    cout << fixed; cout.precision(6);
    cout << (100.0 / ((x / d1) + ((100.0 - x) / d2))) << '\n';

    return 0;
}