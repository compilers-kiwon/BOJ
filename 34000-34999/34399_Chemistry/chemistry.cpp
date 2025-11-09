#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define TBD (-1LL)
#define MAX_LEN (5)
#define MAX_SIZE (40)

typedef long long int int64;

int64 dp[MAX_SIZE];
unordered_set<string> symtab[MAX_LEN+1];

int64 get_dp(int cur_pos, const string& word) {
    if (cur_pos < 0) {
        return ((cur_pos==-1)?1LL:0LL);
    }

    int64& ret = dp[cur_pos];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int length = 1; length <= min(cur_pos + 1, MAX_LEN); length++) {
        string sub = word.substr(cur_pos - length + 1, length);

        if (symtab[length].find(sub) == symtab[length].end()) {
            continue;
        }

        ret += get_dp(cur_pos - length, word);
    }

    return ret;
}

void to_lower_str(const string& str, string& result) {
    for (int i = 0; i < str.length(); i++) {
        result.push_back(tolower(str[i]));
    }
}

void read_symbols(void) {
    int N;

    for (cin >> N; N > 0; N--) {
        string s, lower;
        
        cin >> s;
        to_lower_str(s, lower);
        symtab[lower.length()].insert(lower);
    }
}

int64 simulate(const string& word) {
    fill(dp, dp + MAX_SIZE, TBD);
    return get_dp(word.length() - 1, word);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_symbols();

    int Q;

    for (cin >> Q; Q > 0; Q--) {
        string s;
        cin >> s;
        cout << simulate(s) << '\n';
    }

    return 0;
}