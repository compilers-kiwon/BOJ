#include <iostream>
#include <string>

using namespace std;

const int MSB_POS = 31;
const int LSB_POS = 0;

bool is_palindrome(int num) {
    string s;

    for (int i = MSB_POS; i >= LSB_POS; i--) {
        int n = num & (1 << i);

        if (n != 0) {
            s.push_back('1');
        } else {
            if (!s.empty()) {s.push_back('0');}
        }
    }

    for (int h = 0, t = s.length() - 1; h < t; h++, t--) {
        if (s[h] != s[t]) {
            return false;
        }
    }

    return true;
}

int simulate(int num) {
    int X1, X2, cnt;

    for (X1 = X2 = num, cnt = 0;; cnt++, X1++, X2--) {
        if (is_palindrome(X1) == true || is_palindrome(X2) == true) {
            break;
        }
    }
    
    return cnt;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        int X;
        cin >> X;
        cout << simulate(X) << '\n';
    }

    return 0;
}