#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define int2chr(i) ((char)((i)+(int)'0'))
#define chr2int(c) ((int)((c)-'0'))

string sub(const string& big, const string& small) {
    string ret;
    
    int carry = 0;
    int big_pos = big.length() - 1;
    int small_pos = small.length() - 1;

    for (; big_pos >= 0; big_pos--, small_pos--) {
        int big_num = chr2int(big[big_pos]);
        int small_num = carry + ((small_pos>=0)?chr2int(small[small_pos]):0);

        if (big_num < small_num) {
            big_num += 10, carry = 1;
        } else {
            carry = 0;
        }

        ret.push_back(int2chr(big_num - small_num));
    }

    for (; !ret.empty() && ret.back() == '0';) {
        ret.pop_back();
    }

    if (ret.empty()) {
        ret.push_back('0');
    } else {
        reverse(ret.begin(), ret.end());
    }

    return ret;
}

string get_half(const string& str) {
    string ret;
    int carry = 0;

    for (int i = 0; i < str.length(); i++) {
        int num = (carry * 10) + chr2int(str[i]);
        
        if (num < 2) {
            carry = num, ret.push_back('0');
            continue;
        }

        ret.push_back(int2chr(num / 2));
        carry = num % 2;
    }

    for (; !ret.empty() && ret.front() == '0';) {
        ret.erase(0, 1);
    }

    if (ret.empty()) {
        ret.push_back('0');
    }

    return ret;
}

string add(const string& num1, const string& num2) {
    string ret;
    int carry = 0;
    int num1_pos = num1.length() - 1;
    int num2_pos = num2.length() - 1;

    for (; num1_pos >= 0 || num2_pos >= 0; num1_pos--, num2_pos--) {
        int n1 = (num1_pos>=0)?chr2int(num1[num1_pos]):0;
        int n2 = (num2_pos>=0)?chr2int(num2[num2_pos]):0;

        ret.push_back(int2chr((n1 + n2 + carry) % 10));
        carry = (n1 + n2 + carry) / 10;
    }

    if (carry != 0) {
        ret.push_back(int2chr(carry));
    }

    for (; !ret.empty() && ret.back() == '0';) {
        ret.pop_back();
    }

    if (ret.empty()) {
        ret.push_back('0');
    } else {
        reverse(ret.begin(), ret.end());
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string sum, more, a, b;

    cin >> sum >> more;

    a = sub(sum, more);
    b = get_half(a);

    cout << add(b, more) << '\n' << b << '\n';

    return 0;
}