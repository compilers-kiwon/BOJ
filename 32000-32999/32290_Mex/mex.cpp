#include <iostream>
#include <set>

using namespace std;

void get_numbers(int l, int r, int x, set<int>& s) {
    for (int i = l; i <= r; ++i) {
        s.insert(i | x);
    }
}

int mex(const set<int>& s) {
    int ret = 0;

    for (auto it = s.begin(); it != s.end(); ++it, ++ret) {
        if (*it != ret) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int l, r, x;
    set<int> a;

    cin >> l >> r >> x;
    get_numbers(l, r, x, a);
    cout << mex(a) << '\n';

    return 0;
}