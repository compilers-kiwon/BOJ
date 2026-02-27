#include <iostream>

using namespace std;

int get_gcd(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);

    for (int mod = big % small; mod != 0;) {
        big = small;
        small = mod;
        mod = big % small;
    }

    return small;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    cout << get_gcd(a - 1, b - 1) - 1 << '\n';

    return 0;
}