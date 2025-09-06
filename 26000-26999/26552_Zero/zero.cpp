#include <iostream>
#include <string>

using namespace std;

string get_non_zero_num(int num) {
    string ret = to_string(num);

    for (int i = 0; i < ret.length(); i++) {
        if (ret[i] == '0') {
            ret[i] = '1';
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        int k;
        cin >> k;
        cout << get_non_zero_num(k + 1) << '\n';
    }

    return 0;
}