#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double N;
    
    cin >> N;
    cout << fixed; cout.precision(6);
    cout << (3.0f - (5.0f / sqrt(3.0f))) * N * N << '\n';

    return 0;
}