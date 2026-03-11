#include <iostream>

using namespace std;

int get_gcd(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);
    int mod = big % small;

    while (mod != 0) {
        big = small;
        small = mod;
        mod = big % small;
    }

    return small;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b, g;
        
        cin >> a >> b;
        g = get_gcd(a, b);
        cout << a / g << ' ' << b / g << '\n';
    }

    return 0;
}