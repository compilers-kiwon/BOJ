#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x;
    cin >> x;
    cout << x + ((x>=13)?1:0) << '\n';

    return 0;
}