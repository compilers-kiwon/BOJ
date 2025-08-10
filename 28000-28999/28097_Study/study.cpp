#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;

    for (cin >> N, sum = 0; N > 0; N--) {
        int T;
        cin >> T;
        sum += T + 8;
    }

    sum -= 8;
    cout << (sum / 24) << ' ' << (sum % 24) << '\n';

    return 0;
}