#include <iostream>
#include <string>

using namespace std;

bool find_two_consecutive(const string& str, char c) {
    for (size_t i = 1; i < str.length(); i++) {
        char prev = str[i-1];
        char cur = str[i];

        if (prev == c && cur == c) {
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;

    cin >> s;
    cout << (find_two_consecutive(s, 's')?"":"no ") << "hiss\n";

    return 0;
}