#include <iostream>
#include <string>

using namespace std;

char cur_chr[0x100];

void change(char from, char to) {
    for (char c = 'A'; c <= 'z'; c++) {
        if (cur_chr[c] == from) {
            cur_chr[c] = to;
        }
    }
}

void print(const string& str) {
    string s;

    for (int i = 0; i < str.length(); i++) {
        s.push_back(cur_chr[str[i]]);
    }

    cout << s << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    int n;

    cin >> S >> n;

    for (char c = 'A'; c <= 'z'; c++) {
        cur_chr[c] = c;
    }

    for (int i = 1; i <= n; i++) {
        int q;

        cin >> q;

        if (q == 2) {
            print(S);
        } else {
            char a, b;

            cin >> a >> b;
            change(a, b);
        }
    }

    return 0;
}