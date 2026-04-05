#include <iostream>
#include <string>

using namespace std;

#define int2chr(i) ((char)(i)+'0')
#define chr2int(c) ((int)((c)-'0'))

int find_leftmost_largest_digit_pos(const string& num) {
    int ret;
    char largest_digit = 0x00;

    for (int i = 0; i < num.length(); ++i) {
        if (num[i] > largest_digit) {
            ret = i;
            largest_digit = num[i];
        }
    }

    return ret;
}

void change_num(string& num, int pos) {
    int d = chr2int(num[pos]);

    if ((d % 2) == 0) {
        d = (d + 4) % 10;
    } else {
        d = 0;
    }

    num[pos] = int2chr(d);
}

void print_num(const string& num) {
    int pos;

    for (pos = 0; pos < num.length() && num[pos] == '0'; ++pos) {};

    if (pos == num.length()) {
        cout << "0\n";
    } else {
        cout << num.substr(pos) << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string num;

        cin >> num;

        if (num == "0") {
            break;
        }

        change_num(num, find_leftmost_largest_digit_pos(num));
        print_num(num);
    }

    return 0;
}