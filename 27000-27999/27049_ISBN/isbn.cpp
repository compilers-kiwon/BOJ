#include <iostream>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

bool check_code(const string& code) {
    int sum = 0;

    for (int i = 0, n = 10; i < code.length(); i++, n--) {
        sum += n * (code[i]=='X'?10:chr2int(code[i]));
    }

    return ((sum % 11) == 0);
}

string simulate(string& isbn) {
    int pos = isbn.find('?');

    for (char c = '0'; c <= '9'; c++) {
        isbn[pos] = c;

        if(check_code(isbn) == true) {
            return string(1, c);
        }
    }

    if (pos == isbn.length() - 1) {
        isbn[pos] = 'X';

        if (check_code(isbn) == true) {
            return "X";
        }
    }

    return "-1";
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string isbn;
    cin >> isbn;
    cout << simulate(isbn) << '\n';

    return 0;
}