#include <iostream>
#include <string>

using namespace std;

const string keypad = "22233344455566677778889999";

#define get_idx(c) ((int)((c)-'A'))

void to_upper_str(string& str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}

void to_phone_number(string& str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = keypad[get_idx(str[i])];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string M;

        cin >> M;
        to_upper_str(M);
        to_phone_number(M);
        cout << M << '\n';
    }

    return 0;
}