#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input(vector<string>& s) {
    int N;

    for (cin >> N; N > 0; --N) {
        string name;
        cin >> name;
        s.push_back(name);
    }
}

bool connect(const string& s1, const string& s2) {
    for (int size = 1; size <= min(s1.length(), s2.length()); ++size) {
        string sub1 = s1.substr(s1.length() - size, size);
        string sub2 = s2.substr(0, size);

        if (sub1 == sub2) {
            return true;
        }
    }

    return false;
}

int simulate(const vector<string>& s) {
    int ret = 0;

    for (int i = 0; i < s.size() - 1; ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            ret += (connect(s[i], s[j]) || connect(s[j], s[i]))?1:0;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> s;

    input(s);
    cout << simulate(s) << '\n';

    return 0;
}