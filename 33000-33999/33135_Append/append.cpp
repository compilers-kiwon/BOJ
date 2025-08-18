#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string simulate(string s) {
    string ret;

    sort(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (ret.empty() || s[i] != ret.back()) {
            ret.push_back(s[i]);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans;
    string S;

    cin >> S;

    for (int i = (S.length() / 2); i <= (S.length() - 1); i++) {
        string t = S.substr(0, i);

        if (S == (t + simulate(t))) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}