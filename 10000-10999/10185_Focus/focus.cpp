#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        int p, q, tmp;

        cin >> p >> q;
        tmp = ((p * q) * 100) / (p + q) + 5;
        
        cout << "f = " << tmp / 100 << '.'
                    << (tmp / 10) % 10 << '\n';
    }

    return 0;
}