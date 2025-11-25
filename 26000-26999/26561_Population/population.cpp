#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        int64 p, t;
        cin >> p >> t;
        cout << p + (t / 4) - (t / 7) << '\n';
    }

    return 0;
}