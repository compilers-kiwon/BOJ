#include <iostream>
#include <string>
#include <vector>

using namespace std;

char mate(const string& s, char c1, char c2) {
    return ((s.find(c1)!=string::npos)?c1:c2);
}

char P_mate(const string& s) {
    return mate(s, 'P', 'W');
}

char W_mate(const string& s) {
    return mate(s, 'W', 'P');
}

void input(vector<string>& sub) {
    int n, m, k;
    string s;

    for (cin >> n, s = " "; n > 0; --n) {
        char e;
        cin >> e;
        s.push_back(e);
    }

    for (cin >> m >> k; m > 0; --m) {
        string cur;

        for (int i = 1; i <= k; ++i) {
            int idx;
            cin >> idx;
            cur.push_back(s[idx]);
        }

        sub.push_back(cur);
    }
}

char simulate(const vector<string>& sub) {
    string sum;

    for (int i = 0; i < sub.size(); ++i) {
        sum.push_back(P_mate(sub[i]));
    }

    return W_mate(sum);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> subs;

    input(subs);
    cout << simulate(subs) << '\n';

    return 0;
}