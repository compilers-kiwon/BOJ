#include <iostream>
#include <string>

using namespace std;

#define int2chr(i) ((char)((i)+(int)'0'))

int simulate(const string& cur, const string& result) {
    if (cur == result) {
        return 0;
    }

    string s, tmp;

    for (int i = 0; i < cur.length(); i++) {
        if (!tmp.empty() && tmp.back() != cur[i]) {
            s.push_back(int2chr(tmp.length()));
            s.push_back(tmp.back());
            tmp.clear();
        }

        tmp.push_back(cur[i]);
    }

    s.push_back(int2chr(tmp.length()));
    s.push_back(tmp.back());

    return (1 + simulate(s, result));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S, C;

    cin >> S >> C;
    cout << simulate(S, C) << '\n';

    return 0;
}