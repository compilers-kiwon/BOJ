#include <iostream>

using namespace std;

const int Z = 3;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y;
    cin >> X >> Y;
    cout << X + Y + Z << '\n';

    return 0;
}