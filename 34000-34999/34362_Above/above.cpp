#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double now;

    cin >> now;
    cout << fixed; cout.precision(4);
    cout << now - 0.3f << '\n';

    return 0;
}