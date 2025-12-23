#include <iostream>

using namespace std;

const int START = 9 * 60;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int HH, MM;
    cin >> HH >> MM;
    cout << (HH * 60) + MM - START << '\n';

    return 0;
}