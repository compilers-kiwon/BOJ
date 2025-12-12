#include <iostream>

using namespace std;

const double PI = 3.141592f;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        double A1, P1;
        double R1, P2;
        double piece, whole;

        cin >> A1 >> P1 >> R1 >> P2;
        piece = A1 / P1, whole = (R1 * R1 * PI) / P2;

        cout << ((piece>whole)?"Slice of pizza":"Whole pizza") << '\n';
    }

    return 0;
}