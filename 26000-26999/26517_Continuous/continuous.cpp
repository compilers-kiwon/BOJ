#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;

    int64 f1 = a * k + b;
    int64 f2 = c * k + d;

    if (f1 == f2) {
        cout << "Yes " << f1 << '\n';
    } else {
        cout << "No\n";
    }

    return 0;
}