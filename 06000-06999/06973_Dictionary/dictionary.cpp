#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void get_text_set(vector<string>& text_set) {
    for (;;) {
        string buf;

        getline(cin, buf);

        if (buf.empty()) {
            break;
        }

        text_set.push_back(buf);
    }
}

void get_words(const string& str, vector<string>& w) {
    string cur;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            w.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

void analyze_text(vector<string>& text_set, vector<vector<string>>& word_set) {
    for (int i = 0; i < text_set.size(); ++i) {
        vector<string> words;

        text_set[i].push_back(' ');
        get_words(text_set[i], words);
        word_set.push_back(words);
    }
}

void print(const vector<vector<string>>& word_set) {
    int idx = 1;
    unordered_map<string, int> dic;

    for (int line = 0; line < word_set.size(); ++line) {
        const vector<string>& words = word_set[line];

        for (int j = 0; j < words.size(); ++j) {
            auto it = dic.find(words[j]);
            
            if (it == dic.end()) {
                cout << words[j], dic[words[j]] = idx++; 
            } else {
                cout << it->second;
            }

            cout << ((j==words.size()-1)?'\n':' ');
        }
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string buf;
    getline(cin, buf);
    
    for (int n = stoi(buf); n > 0; --n) {
        vector<string> text_set;
        vector<vector<string>> word_set;

        get_text_set(text_set);
        analyze_text(text_set, word_set);
        print(word_set);
    }

    return 0;
}