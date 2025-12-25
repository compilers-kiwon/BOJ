#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 H, S;

    cin >> H >> S;

    if (H <= 2LL) {
        cout << "1\n";
    } else if (H <= 4LL) {
        cout << (H + 1LL) / 2LL + S << '\n';
    } else {
        if (H % 2LL == 0) {
            if (S % 2LL == 0) {
                cout << (H + 1LL) / 2LL + (S / 2LL) * 3LL << '\n';
            } else {
                cout << (H + 1LL) / 2LL + ((S - 1LL) / 2LL) * 3LL + 2LL << '\n';
            }
        } else {
            if (S % 2LL == 0) {
                cout << (H + 1LL) / 2LL + (S / 2LL) * 3LL << '\n';
            } else {
                cout << (H + 1LL) / 2LL + ((S - 1LL) / 2LL) * 3LL + 1LL << '\n';
            }
        }
    }

    return 0;
}