#include <iostream>
#include <string>

using namespace std;

typedef long long int int64;

#define NONE ("")
#define chr2int64(c) ((int64)((c)-'0'))

bool is_dividable(int64 num, int64 src) {
    for (; src > 0LL; src /= 10LL) {
        int64 d = src % 10LL;

        if (d != 0LL && num % d != 0LL) {
            return false;
        }
    }

    return true;
}

string find_num(string& num, int target_length, int64 src) {
    if (num.length() == target_length) {
        return (is_dividable(stoll(num), src)?num:NONE);
    }

    string ret;

    for (char c = '0'; c <= '9'; ++c) {
        num.push_back(c);

        if ((ret = find_num(num, target_length, src)) != NONE) {
            break;
        }

        num.pop_back();
    }

    return ret;
}

string simulate(string num, int64 src) {
    string ret;

    for (int len = num.length() + 1;; ++len) {
        if ((ret = find_num(num, len, src)) != NONE) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string num;
    
    cin >> num;
    
    if (is_dividable(stoll(num), stoll(num))) {
        cout << num << '\n';
    } else {
        cout << simulate(num, stoll(num)) << '\n';
    }

    return 0;
}