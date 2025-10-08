#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        string param;
        char equal;
        double num;

        cout.unsetf(ios::fixed);
        cin >> param >> equal >> num;
        
        cout << fixed;
        cout.precision(2);
        
        if (param == "H") {
            cout << -log10(num) << '\n';
        } else {
            cout << 14 + log10(num) << '\n';
        }
    }

    return 0;
}