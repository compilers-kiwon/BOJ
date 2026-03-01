#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, v;
    vector<int> num;

    for (cin >> n >> v; n > 1; --n) {
        int a;
        cin >> a;
        num.push_back(-a);
    }

    sort(num.begin(), num.end());
    cout << (int)(lower_bound(num.begin(), num.end(), -v) - num.begin()) + 1 << '\n';

    return 0;
}