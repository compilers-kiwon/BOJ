#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& str) {
    for (int h = 0, t = str.length() - 1; h < t; h++, t--) {
        if (str[h] != str[t]) {
            return false;
        }
    }

    return true;
}

string ignore_non_alpha(const string& str) {
    string ret;

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            ret.push_back(tolower(str[i]));
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;

    getline(cin, str);
    str = ignore_non_alpha(str);

    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = 2; j <= str.length(); j++) {
            string sub = str.substr(i, j);
            
            if (is_palindrome(sub) == true) {
                cout << "Palindrome\n";
                return 0;
            }
        }
    }

    cout << "Anti-palindrome\n";

    return 0;
}