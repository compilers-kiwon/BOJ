#include <iostream>
#include <string>

using namespace std;

const string word = "certainly";

int count_word(const string& s, const string& w) {
    int ret = 0;
    size_t pos = 0;

    for (;;) {
        if ((pos = s.find(w, pos)) != string::npos) {
            ret++, pos += w.length();
        } else {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;

    getline(cin, s);
    cout << count_word(s, word) << '\n';

    return 0;
}