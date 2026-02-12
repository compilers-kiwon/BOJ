#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    double sum, c;

    for (cin >> n, sum = 0.0; n > 0; --n) {
        cin >> c;
        sum += c * c * c;
    }
    
    cout << fixed; cout.precision(6);
    cout << cbrt(sum) << '\n';

    return 0;
}