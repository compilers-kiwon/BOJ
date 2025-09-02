#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define get_sign(n) ((n)==0?0:(n)/abs(n))

string solve(int d1, const string str1, int d2, const string str2) {
    string ret;
    int diff = d1 - d2;

    switch (get_sign(diff)) {
        case -1: ret = str1; break;
        case 1: ret = str2; break;
        case 0: default: ret = "Either"; break;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << solve(A + C, "Hanyang Univ.", B + D, "Yongdap") << '\n';

    return 0;
}