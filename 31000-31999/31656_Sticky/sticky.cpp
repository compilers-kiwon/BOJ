#include <iostream>
#include <string>

using namespace std;

string simulate(const string& s) {
    string ret = "_";

    for (int i = 0; i < s.length(); ++i) {
        if (ret.back() != s[i]) {
            ret.push_back(s[i]);
        }
    }

    ret.erase(0,1);
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    getline(cin, S);
    cout << simulate(S) << '\n';

    return 0;
}