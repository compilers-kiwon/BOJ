#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    cout << (n - 1) * x << '\n';

    return 0;
}