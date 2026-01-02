#include <iostream>
#include <string>

using namespace std;

const string usable = "01698";

int simulate(int lower, int upper) {
    int ret = 0;

    for (int i = lower; i <= upper; i++) {
        bool available = true;
        string num = to_string(i);

        for (int h = 0, t = num.length() - 1; h <= t; h++, t--) {
            char d1 = num[h];
            char d2 = num[t];

            if (usable.find(d1) == string::npos
                || usable.find(d2) == string::npos) {
                available = false;
                break;
            }

            if (d1 != '6' && d1 != '9' && d1 != d2) {
                available = false;
                break;
            }

            if ((d1 == '6' && d2 != '9') || (d1 == '9' && d2 != '6')) {
                available = false;
                break;
            }
        }

        ret += available?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    cout << simulate(m, n) << '\n';

    return 0;
}