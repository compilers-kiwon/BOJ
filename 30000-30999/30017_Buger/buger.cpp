#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;

    cin >> A >> B;
    B = min(B, A - 1);
    A = min(A, B + 1);

    cout << A + B << '\n';

    return 0;
}