#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int P, Q, A, B;

    cin >> P >> Q >> A >> B;
    cout << (min(P, Q) * A) + (max(0, Q - P) * B) << '\n';

    return 0;
}