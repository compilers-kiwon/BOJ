#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

typedef pair<int, int> Pos;

void get_pairs(const string& exp, vector<Pos>& p) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        switch (exp[i]) {
            case '(': st.push(i); break;
            case ')': p.push_back({st.top(), i}); st.pop(); break;
            default: /*do nothing*/; break;
        }
    }
}

void build_exp_without_paren(const string& exp, bool removed[], set<string>& s) {
    string new_exp;

    for (int i = 0; i < exp.length(); i++) {
        if (removed[i] == true) {
            continue;
        }

        new_exp.push_back(exp[i]);
    }

    s.insert(new_exp);
}

void dfs(int cur_pair_idx, const vector<Pos>& p,
            bool removed[], const string& exp, set<string>& s) {
    if (cur_pair_idx == p.size()) {
        build_exp_without_paren(exp, removed, s);
        return;
    }

    Pos cur = p[cur_pair_idx];

    removed[cur.first] = removed[cur.second] = true;
    dfs(cur_pair_idx + 1, p, removed, exp, s);
    removed[cur.first] = removed[cur.second] = false;

    dfs(cur_pair_idx + 1, p, removed, exp, s);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string exp;

    cin >> exp;

    vector<Pos> p;
    set<string> ans;
    bool removed[exp.length()] = {false, };

    get_pairs(exp, p);
    dfs(0, p, removed, exp, ans);

    ans.erase(exp);

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}