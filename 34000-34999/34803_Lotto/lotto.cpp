#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MAX_SIZE (20+1)

string lotto[MAX_SIZE];
unordered_set<string> all;
unordered_map<string, int> sub_table[MAX_SIZE];

void get_sub_str(const string& str, int sub_length,
                    unordered_map<string, int>& table) {
    for (int i = 0; i <= str.length() - sub_length; i++) {
        string sub = str.substr(i, sub_length);
        all.insert(sub), table[sub]++;
    }
}

int input(void) {
    int L, N, K;

    cin >> L >> N;

    for (int i = 1; i <= N; i++) {
        cin >> lotto[i];
    }

    cin >> K;
    for (int i = 1; i <= N; i++) {
        get_sub_str(lotto[i], K, sub_table[i]);
    }

    return N;
}

int get_score(const string& s, int num_of_lotto) {
    int ret = 0;

    for (int i = 1; i <= num_of_lotto; i++) {
        auto it = sub_table[i].find(s);

        if (it != sub_table[i].end()) {
            ret += it->second;
        }
    }

    return ret;
}

int simulate(int num_of_lotto) {
    int ret = 0;

    for (auto it = all.begin(); it != all.end(); it++) {
        ret = max(ret, get_score(*it, num_of_lotto));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_lotto = input();
    cout << simulate(num_of_lotto) << '\n';

    return 0;
}