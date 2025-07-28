#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

string get_product(const string& a, int b) {
    string ret;
    int carry = 0;

    for (int i = a.length() - 1; i >= 0; i--) {
        int num = (chr2int(a[i]) * b) + carry;
        carry = num / 10;
        ret = to_string(num % 10) + ret;
    }

    if (carry != 0) {
        ret = to_string(carry) + ret;
    }

    return ret;
}

string get_sum(const string& a, const string& b) {
    string ret;
    int a_pos, b_pos, carry;

    carry = 0;

    for (a_pos = a.length() - 1, b_pos = b.length() - 1;
            (a_pos >= 0) || (b_pos >= 0); a_pos--, b_pos--) {
        int a_digit = (a_pos >= 0)?chr2int(a[a_pos]):0;
        int b_digit = (b_pos >= 0)?chr2int(b[b_pos]):0;
        int cur_digit = a_digit + b_digit + carry;

        carry = cur_digit / 10;
        ret = to_string(cur_digit % 10) + ret;
    }

    if (carry != 0) {
        ret = to_string(carry) + ret;
    }

    return ret;
}

bool is_zero(const string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            return false;
        }
    }

    return true;
}

string get_result(const string& a, const string& b) {
    string ret;
    vector<string> result;

    for (int i = b.length() - 1; i >= 0; i--) {
        string p = get_product(a, chr2int(b[i]));
        result.push_back(p);
    }

    for (int i = 0; i < result.size(); i++) {
        if (is_zero(result[i]) == true) {
            result[i] = "0";
            cout << "0\n";
            continue;
        }

        cout << result[i] << '\n';

        for (int j = 0; j < i; j++) {
            result[i].push_back('0');
        }
    }

    ret = result.front();

    for (int i = 1; i < result.size(); i++) {
        ret = get_sum(ret, result[i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string a, b;

    cin >> a >> b;
    cout << a << '\n' << b << '\n' << get_result(a, b) << '\n';

    return 0;
}