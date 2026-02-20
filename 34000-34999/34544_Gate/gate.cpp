#include <iostream>
#include <cmath>

using namespace std;

#define get_sign(n) ((n)>0?1:-1)

int get_diff(int enter, int exit) {
    int ret = exit - enter;

    if (get_sign(enter) != get_sign(exit)) {
        int s = get_sign(ret);
        ret = s * (abs(ret) - 1);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cur;

    for (cin >> N, cur = 0; N > 0; --N) {
        int A, B;
        cin >> A >> B;
        cur += get_diff(A, B);
    }

    cout << ((cur>=0)?cur+1:cur) << '\n';
    return 0;
}