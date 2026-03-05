#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 a, b, c, d;

    cin >> a >> b;
    c = a * b;
    d = (c / 4840LL) + ((c%4840LL)==0LL?0LL:1LL);

    cout << (d / 5LL) + ((d%5LL)==0LL?0LL:1LL) << '\n';
    return 0;
}