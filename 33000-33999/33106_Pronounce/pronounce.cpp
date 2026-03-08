#include <iostream>
#include <string>

using namespace std;

bool s_pronounce(char c) {
    const string str = "eiy";
    return (str.find(c) != string::npos);
}

bool c_pronounce(char c) {
    return (c == 'h');
}

string simulate(const string& str) {
    string tmp(1, str.front());

    for (int i = 1; i < str.length(); ++i) {
        char c = str[i];

        if (tmp.back() != 'c') {
            tmp.push_back(c);
            continue;
        }

        if (s_pronounce(c) == true) {
            tmp.back() = 's';
        } else if (c_pronounce(c) == true) {
            tmp.back() = 'c';
        } else {
            tmp.back() = 'k';
        }

        if (c != 'h') {
            tmp.push_back(c);
        } else {
            tmp.push_back(' ');
        }
    }

    if (tmp.back() == 'c') {
        tmp.back() = 'k';
    } 

    string ret;

    for (int i = 0; i < tmp.length(); ++i) {
        if (tmp[i] != ' ') {
            ret.push_back(tmp[i]);
        }
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; --N) {
        string s;
        cin >> s;
        cout << simulate(s) << '\n';
    }

    return 0;
}