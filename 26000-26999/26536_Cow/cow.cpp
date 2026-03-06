#include <iostream>
#include <vector>
#include <string>

using namespace std;

char get_char(const string& str) {
    char ret = 0x00;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'M') {
            ret += 0x10;
        } else {
            ret += 0x01;
        }
    }

    return ret;
}

void parse(const string& str, vector<string>& s) {
    string w;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            if (w.empty()) {
                continue;
            }

            s.push_back(w);
            w.clear();
        } else {
            w.push_back(str[i]);
        }
    }
}

string simulate(const vector<string>& s) {
    string ret;

    for (int i = 0; i < s.size(); ++i) {
        ret.push_back(get_char(s[i]));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string n;
    getline(cin, n);

    for (int i = 0; i < stoi(n); ++i) {
        string str;
        vector<string> s;

        getline(cin, str);
        str.push_back(' '); parse(str, s);
        cout << simulate(s) << '\n';
    }

    return 0;
}