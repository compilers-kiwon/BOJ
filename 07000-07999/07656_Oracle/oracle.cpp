#include <iostream>
#include <vector>
#include <string>

using namespace std;

void input(vector<string>& s) {
    string str, cur;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        const char c = str[i];

        if (isupper(c)) {
            if (!cur.empty()) {
                for(; cur.back() == ' '; cur.pop_back());
                s.push_back(cur);
                cur.clear();
            }
        }

        cur.push_back(c);
    }

    if (!cur.empty()) {
        for(; cur.back() == ' '; cur.pop_back());
        s.push_back(cur);
    }
}

void get_answer(const vector<string>& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i].length() < 8) {
            continue;
        }

        if (s[i].substr(0, 7) != "What is") {
            continue;
        }

        if (s[i].back() != '?') {
            continue;
        }

        string ans = "Forty-two" + s[i].substr(4, 0x7FFFFFFF);
        ans.back() = '.';
        cout << ans << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> sen;

    input(sen);
    get_answer(sen);

    return 0;
}