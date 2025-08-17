#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    long long int a, b;

    cin >> a >> b;
    cout << fixed; cout.precision(8);
    cout << sqrt((a * a) + (b * b)) << '\n';

    return 0;
}