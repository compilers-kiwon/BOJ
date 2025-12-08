#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, D, P;

    for (cin >> N, D = P = 0; N > 0; N--) {
        char winner;

        cin >> winner;
        
        if (winner == 'D') {
            D++;
        } else {
            P++;
        }

        if (abs(D - P) == 2) {
            break;
        }
    }

    cout << D << ':' << P << '\n';

    return 0;
}