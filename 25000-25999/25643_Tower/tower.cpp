#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input(vector<string>& s) {
    int N, M;
    
    for (cin >> N >> M; N > 0; --N) {
        string str;
        cin >> str;
        s.push_back(str);
    }
}

bool analyze_str(const string& left, const string& right) {
    for (int i = left.length() - 1, len = 1; i >= 0; --i, ++len) {
        if (left[i] == right.front() &&
                left.substr(i, len) == right.substr(0, len)) {
            return true;
        }
    }

    return false;
}

int simulate(const vector<string>& s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (analyze_str(s[i], s[i+1]) == false
                && analyze_str(s[i+1], s[i]) == false) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> s;

    input(s);
    cout << simulate(s) << '\n';

    return 0;
}