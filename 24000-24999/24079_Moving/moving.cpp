#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y, Z;
    cin >> X >> Y >> Z;
    cout << ((X+Y<=Z)?1:0) << '\n';

    return 0;
}