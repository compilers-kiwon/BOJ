#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void analyze_word(unordered_map<string, int>& table, const string& s) {
    string sub;

    for (int i = 0; i < s.length(); i++) {
        sub.push_back(s[i]);
        table[sub]++;
    }
}

void input(unordered_map<string, int> table[], vector<string>& words) {
    int N;

    if (!(cin >> N)) {
        return;
    }

    for (int i = 1; i <= N; i++) {
        string s;

        cin >> s;
        words.push_back(s);
        analyze_word(table[s.front()], s);
    }
}

int input(unordered_map<string, int>& table, const string& s) {    
    int ret, tag;
    string sub_str;

    ret = tag = 0;

    for (int i = 0; i < s.length(); i++) {
        sub_str.push_back(s[i]);
        ret += (tag!=table[sub_str])?1:0;
        tag = table[sub_str];
    }

    return ret;
}

double simulate(unordered_map<string, int> table[],
                    const vector<string>& words) {
    int sum = 0;

    for (int i = 0; i < words.size(); i++) {
        const string s = words[i];
        sum += input(table[s.front()], s);
    }

    return ((double)sum)/((double)words.size());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout << fixed; cout.precision(2);

    for (;;) {
        vector<string> words;
        unordered_map<string, int> table[0x100];

        input(table, words);

        if (words.empty()) {
            break;
        }

        cout << simulate(table, words) << '\n';
    }

    return 0;
}