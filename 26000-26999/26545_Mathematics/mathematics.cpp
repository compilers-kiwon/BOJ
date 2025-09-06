#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, sum;

    for (cin>> n, sum = 0; n > 0; n--) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << sum << '\n';
    return 0;
}