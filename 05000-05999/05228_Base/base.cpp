#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string digits = "0123456789abcdefghijklmnopqrs";

void convert(int n, int k, string& result) {
    for (; n > 0; n /= k) {
        result.push_back(digits[n%k]);
    }

    reverse(result.begin(), result.end());
}

bool simulate(int n, int k, string &num) {
    if (n == 0) {
        num.push_back('0');
        return false;
    }

    convert(n, k, num);

    for (int i = 0; i < k; i++) {
        if (num.find(digits[i]) == string::npos) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int n, k;
        string num;

        cin >> n >> k;

        if (simulate(n, k, num) == true) {
            cout << "Base-" << k << " representation of "
                    << n << " is " << num << "; contains all digits.\n";
        } else {
             cout << "Base-" << k << " representation of "
                    << n << " is " << num << "; does not contain all digits.\n";
        }
    }

    return 0;
}