#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C, D, bus, walk;

    cin >> A >> B >> C >> D;
    bus = A + B, walk = C;

    if (bus <= D && walk <= D) {
        cout << "~.~\n";
    } else if (bus > D && walk > D) {
        cout << "T.T\n";
    } else if (bus <= D) {
        cout << "Shuttle\n";
    } else {
        cout << "Walk\n";
    }

    return 0;
}