#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double W, m, C;
    cin >> W >> m >> C;
    
    cout << fixed; cout.precision(0);
    cout << ceil((W * m) * (C / (60.0 * 1000.0)) / 100.0) << '\n';

    return 0;
}