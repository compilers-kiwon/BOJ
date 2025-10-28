#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string s = "ROYGP";
int num_of_skittles[0x100];

bool is_available(const string& cur) {
    for (int i = 0; i < cur.length(); i++) {
        if (num_of_skittles[cur[i]] == 0) {
            return false;
        }
    }

    return true;
}

int eat_skittles(const string& cur) {
    int min_num = 0x7FFFFFFF;

    for (int i = 0; i < cur.length(); i++) {
        min_num = min(min_num, num_of_skittles[cur[i]]);
    }

    for (int i = 0; i < cur.length(); i++) {
        num_of_skittles[cur[i]] -= min_num;
    }

    return min_num;
}

int dfs(string& selected, int idx, int size) {
    int ret = 0;

    if (idx == s.length()) {
        if (selected.length() == size) {
            if (is_available(selected) == true) {
                ret = eat_skittles(selected);
            }
        }

        return ret;
    }

    selected.push_back(s[idx]);

    if ((ret = dfs(selected, idx + 1, size)) != 0) {
        return ret;
    }

    selected.pop_back();

    return (dfs(selected, idx + 1, size));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string skittles;
    
    for (cin >> skittles; !skittles.empty(); skittles.pop_back()) {
        num_of_skittles[skittles.back()]++;
    }

    for (int i = s.length(); i > 0; i--) {
        int cnt;
        string cur;

        cnt = dfs(cur, 0, i);
        cout << cnt << ((cnt!=0)?" "+cur:"") << '\n';
    }

    return 0;
}