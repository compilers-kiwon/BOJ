#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cur, credit;

    for (cin >> N, cur = credit = 0; N > 0; N--) {
        char c;
        int A;

        cin >> c >> A;

        if (c == 'G') {
            cur += A;
        } else {
            cur -= A;

            if (cur < 0) {
                credit += -cur;
                cur = 0;
            }
        }
    }

    cout << credit << '\n';
    return 0;
}