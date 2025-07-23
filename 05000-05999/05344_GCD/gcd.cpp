#include <iostream>

using namespace std;

int get_gcd(int big, int small) {
    for (int mod = big % small; mod != 0; mod = big % small) {
        big = small;
        small = mod;
    }

    return small;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (; n > 0; n--) {
        int a, b;

        cin >> a >> b;
        cout << get_gcd(max(a, b), min(a, b)) << '\n';
    }

    return 0;
}