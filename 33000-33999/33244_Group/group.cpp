#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;

int64 get_gcd(int64 a, int64 b) {
    int64 big = max(a, b);
    int64 small = min(a, b);

    for (int mod = big % small; mod != 0; mod = big % small) {
        big = small;
        small = mod;
    }

    return small;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    vector<int64> num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int64 required;
        cin >> required;
        num.push_back(required);
    }

    int64 lcm = num[0];

    for (int i = 1; i < n; i++) {
        int64 gcd = get_gcd(lcm, num[i]);
        lcm *= num[i] / gcd;
    }

    cout << lcm << '\n';

    return 0;
}