#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& str, bool skip_head, bool skip_tail) {
    for (int h = 0, t = str.length() - 1; h < t; h++, t--) {
        if (str[h] != str[t]) {
            if (skip_head == true) {
                skip_head = false, h++;
                
                if (h >= t || str[h] == str[t]) {
                    continue;
                }
            }

            if (skip_tail == true) {
                skip_tail = false, t--;
                
                if (h >= t || str[h] == str[t]) {
                    continue;
                }
            }

            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        string s;

        cin >> s;

        if (is_palindrome(s, false, false) == true) {
            cout << "0\n";
            continue;
        }

        if (is_palindrome(s, true, false) == true
                || is_palindrome(s, false, true) == true) {
            cout << "1\n";
            continue;
        }

        cout << "2\n";
    }

    return 0;
}