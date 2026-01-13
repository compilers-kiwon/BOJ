#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

string transfer(const vector<string>& rule, deque<char>& input) {
    string ret;

    for (int i = 0; !input.empty();) {
        if (i == rule.size() || rule[i].front() != input.front()) {
            ret.push_back(input.front());
            input.pop_front();
        } else {
            const string& s = rule[i+1];
            
            input.pop_front(), i += 2;
            input.push_front(s.back());
            input.push_front(s.front());
        }
    }

    return ret;
}

void parse(const string& in, vector<string>& ret) {
    string cur;

    for (int i = 0; i < in.length(); i++) {
        if (in[i] == ' ') {
            ret.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(in[i]);
        }
    }
}

void analyze_word(const string& w, deque<char>& dq) {
    for (int i = 0; i < w.length(); i++) {
        dq.push_back(w[i]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num;
    string t;

    getline(cin, t);
    num = stoi(t);

    for (int i = 1; i <= num; i++) {
        string in;
        vector<string> rule, word;

        getline(cin, in); in.push_back(' ');
        parse(in, rule);

        getline(cin, in); in.push_back(' ');
        parse(in, word);

        cout << "Transformed strings: ";

        for (int i = 0; i < word.size(); i++) {
            deque<char> dq;
            analyze_word(word[i], dq);
            cout << transfer(rule, dq) << ((i==word.size()-1)?'\n':' ');
        }
    }

    return 0;
}