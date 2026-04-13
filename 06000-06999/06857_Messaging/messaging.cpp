#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> keys = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
};

pair<size_t, size_t> get_pos(char c) {
    size_t i, j;

    for (i = 0; i < keys.size(); ++i) {
        if ((j = keys[i].find(c)) != string::npos) {
            break;
        }
    }

    return {i, j};
}

size_t simulate(const string& str) {
    size_t ret = 0;
    size_t prev = keys.size();

    for (size_t i = 0; i < str.length(); ++i) {
        pair<size_t, size_t> p = get_pos(str[i]);
        ret += (p.second + 1) + ((p.first==prev)?2:0);
        prev = p.first;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string s;
        
        cin >> s;

        if (s == "halt") {
            break;
        }

        cout << simulate(s) << '\n';
    }

    return 0;
}