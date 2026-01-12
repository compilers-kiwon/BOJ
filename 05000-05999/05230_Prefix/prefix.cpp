#include <iostream>
#include <string>
#include <vector>

using namespace std;

void simulate(int code_pos, const string& code,
                const string& prefix, string& decoded) {
    if (code_pos == code.length()) {
        return;
    }

    for (int ptr = 0; ptr < prefix.length();
         ptr = (ptr * 2) + (code[code_pos++]=='0'?1:2)) {
        if (prefix[ptr] != '*') {
            decoded.push_back(prefix[ptr]);
            break;
        }
    }

    simulate(code_pos, code, prefix, decoded);
}

void input(string& prefix, vector<string>& code) {
    int k;

    for (cin >> k >> prefix; k > 0; k--) {
        string c;
        cin >> c;
        code.push_back(c);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        string p;
        vector<string> c;

        input(p, c);
        
        for (int i = 0; i < c.size(); i++) {
            string decoded;
            simulate(0, c[i], p, decoded);
            cout << decoded << ((i==c.size()-1)?'\n':' ');
        }
    }

    return 0;
}