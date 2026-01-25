#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void get_digits(string& d) {
    for (int i = 0; i <= 9; i++) {
        char c;
        cin >> c;
        d.push_back(c);
    }
}

int inverse_func(const string& digits) {
    int ret;
    string num;

    cin >> num, ret = 0;

    for (int i = 0; i < num.length(); i++) {
        int pos = digits.find(num[i]);
        ret = ret * 10 + pos;
    }

    return ret;
}

string func(int num, const string& digits) {
    string ret;

    for (; num > 0; num /= 10) {
        ret.push_back(digits[num%10]);
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;
    string digits;

    get_digits(digits);
    
    A = inverse_func(digits);
    B = inverse_func(digits);
    
    cout << func(A + B, digits) << '\n';
    return 0;
}