#include <iostream>
#include <string>
#include <map>

using namespace std;

void get_head_chr(const string& s, map<char, int>& table) {
    string cur;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (!cur.empty()) {
                table[cur.front()]++;
                cur.clear();
            }
        } else {
            cur.push_back(s[i]);
        }
    }
}

char find_most_head(const map<char, int>& table) {
    char ret;
    int max_cnt = 0;

    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second > max_cnt) {
            ret = it->first;
            max_cnt = it->second;
        }
    }

    return ret;
}

int main(void) {
    int N;

    cin>> N;
    getchar();

    for (int i = 1; i <= N; i++) {
        string s;
        map<char, int> table;

        getline(cin, s);
        s.push_back(' ');

        get_head_chr(s, table);
        cout << find_most_head(table) << '\n';
    }

    return 0;
}