#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 n, a, b, c;

    cin >> n;
    a = 1, b = 3, c = 3;

    for (int64 i = 1; i < n; i++) {
        a += b;
        b += c;
        c++;
    }

    cout << a << '\n';

    return 0;
}