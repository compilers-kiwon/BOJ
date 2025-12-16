#include <iostream>

using namespace std;

const int TUESDAY = 2;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X;
    cin >> X;
    cout << ((X%7==TUESDAY)?1:0) << '\n';

    return 0;
}