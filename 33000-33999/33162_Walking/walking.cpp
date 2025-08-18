#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X;
    cin >> X;
    cout << (X / 2) + ((X%2==1)?3:0) << '\n';

    return 0;
}