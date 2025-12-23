#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long uint64;

#define chr2int(c) ((int)((c)-'0'))

uint64 get_abs(const string& num) {
    uint64 ret = 0ULL;

    for (int i = 0; i < num.length(); i++) {
        if (isdigit(num[i])) {
            ret = (ret * 10ULL) + (uint64)chr2int(num[i]);
        }
    }

    return ret;
}

string calculate(uint64 a, uint64 b) {
    string ret = to_string(a * b);

    for (; ret.length() < 19;) {
        ret.insert(ret.begin(), '0');
    }

    int d_offset = ret.length() - 18;
    ret.insert(ret.begin() + d_offset,'.');

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string A, B;
        uint64 a, b;
        bool negative;

        cin >> A >> B;

        negative = (A.front()=='-' && B.front()!='-')
                    || (A.front()!='-' && B.front()=='-');
        a = get_abs(A), b = get_abs(B);

        cout << (negative?"-":"") << calculate(a, b) << '\n';
    }

    return 0;
}