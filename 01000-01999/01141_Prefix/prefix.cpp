#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_bigger(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return (s1.length() > s2.length());
    }

    return (s1 > s2);
}

void input(vector<string>& words) {
    int N;

    for (cin >> N; N > 0; N--) {
        string w;
        cin >> w;
        words.push_back(w);
    }

    sort(words.begin(), words.end(), is_bigger);
}

bool find_prefix(const vector<string>& p, const string& w) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i].substr(0, w.length()) == w) {
            return true;
        }
    }

    return false;
}

int simulate(const vector<string>& words) {
    vector<vector<string>> s;

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (find_prefix(s[j], words[i]) == false) {
                s[j].push_back(words[i]);
            }
        }

        vector<string> n = {words[i]};
        s.push_back(n);
    }

    int ret = 0;

    for (int i = 0; i < s.size(); i++) {
        ret = max(ret, (int)s[i].size());
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> words;

    input(words);
    cout << simulate(words) << '\n';

    return 0;
}