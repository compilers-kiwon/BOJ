#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double K;
    int N, R;

    cin >> K >> N >> R;

    double p1 = 1.0f - pow(1.0f - K, N);
    double p2 = 1.0f - pow(p1, R);

    cout << fixed; cout.precision(5);
    cout << p2 << '\n';

    return 0;
}