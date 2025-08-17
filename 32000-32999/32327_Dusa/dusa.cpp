#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int D, Y;

    cin >> D;
    
    for (;cin >> Y; D += Y) {
        if (D <= Y) break;
    }

    cout << D << '\n';

    return 0;
}