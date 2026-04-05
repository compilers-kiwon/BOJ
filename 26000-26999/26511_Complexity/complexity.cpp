#include <iostream>
#include <string>
#include <set>

using namespace std;

void count_num_of_letters(const string& s, int cnt[]) {
    for (int i = 0; i < s.length(); ++i) {
        ++cnt[s[i]];
    }
}

int simulate(int cnt[]) {
    int ret = 0;
    multiset<int> s;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] != 0) {
            s.insert(cnt[c]);
        }
    }

    for (; s.size() > 2; s.erase(s.begin())) {
        ret += *s.begin();
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string s;
        int cnt[0x100];

        cin >> s, fill(cnt, cnt + 0x100, 0);
        count_num_of_letters(s, cnt);
        cout << simulate(cnt) << '\n';
    }

    return 0;
}