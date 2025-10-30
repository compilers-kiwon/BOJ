#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y, Z;
    char d, p;

    cin >> X >> d >> Y >> p >> Z;

    int min_val = X + Z;
    int max_val = (X * Y) + Z;

    cout << (min_val + max_val) / 2 <<
            ((min_val + max_val)%2==0?"":".5") << '\n';

    return 0;
}