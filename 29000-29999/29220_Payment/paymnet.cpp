#include <iostream>

using namespace std;

int input(int& min_val, int& sum) {
    int k, n;

    for (cin >> k >> n; n > 0; n--) {
        int a;
        cin >> a;
        min_val = min(min_val, a), sum += a;
    }

    return k;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int k, min_val, sum;

    min_val = 0x7FFFFFFF, sum = 0;
    k = input(min_val, sum);
    cout << (((sum-min_val)<k)?"NO":"YES") << '\n';

    return 0;
}