#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define INF (0x7FFFFFFF)
#define int2chr(n) ((char)((n)+'0'))
#define chr2int(c) ((int)((c)-'0'))

string convert_number(int num, int base) {
    string ret;

    for (; num > 0; num /= base) {
        ret.push_back(int2chr(num % base));
    }

    for (; ret.back() == '0'; ret.pop_back()) {}
    reverse(ret.begin(), ret.end());

    return ret;
}

bool is_bigger(const string& n1, const string& n2) {
    if (n1.length() != n2.length()) {
        return (n1.length() > n2.length());
    }

    if (n1 == n2) {
        return false;
    }

    bool ret;
    
    for (int i = 0; i < n1.length(); ++i) {
        if (n1[i] < n2[i]) {
            ret = false;
            break;
        }

        if (n1[i] > n2[i]) {
            ret = true;
            break;
        }
    }

    return ret;
}

int str2int(const string& num, int base) {
    int ret = 0;

    for (int i = 0; i < num.length(); ++i) {
        ret = (ret * base) + chr2int(num[i]);
    }

    return ret;
}

int find_number(const string& lower, int base) {
    if (lower.length() > base) {
        return -1;
    }

    string cur;
    int ret = INF;

    for (char c = '0'; c < int2chr(base); ++c) {
        cur.push_back(c);
    }

    do {
        if (cur.front() == '0') {
            continue;
        }
        
        if (is_bigger(cur, lower) == true) {
            ret = min(ret, str2int(cur, base));
            break;
        }
    } while(next_permutation(cur.begin(), cur.end()));

    return ((ret==INF)?-1:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, d;
    string num;

    cin >> N >> d;
    num = convert_number(N, d);
    cout << find_number(num, d) << '\n';

    return 0;
}