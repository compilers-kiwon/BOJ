#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const double pi = 3.14159;
    double d, w, n;

    cin >> d >> w >> n;
    cout << (((d * pi) >= (w * n))?"YES":"NO") << '\n';

    return 0;
}