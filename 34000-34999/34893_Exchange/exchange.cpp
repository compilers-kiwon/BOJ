#include <iostream>

using namespace std;

typedef long long int int64;

int64 bin_search(int64 U, int64 S, int64 lo, int64 hi) {
    int64 ret = 0;

    for (; lo <= hi;) {
        int64 mid = (lo + hi) / 2;
        int64 U_dec = 2 * mid;
        int64 S_inc = mid;

        if ((U - U_dec) >= mid && (S + S_inc) >= mid) {
            ret = mid, lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 U, O, S, cnt;

    for (cin >> U >> O >> S, cnt = 0; U != 0 && S != 0;) {
        int64 min_num = min(U, min(O, S));

        cnt += min_num;
        U -= min_num, O -= min_num, S -= min_num;

        if (O == 0) {
            break;
        }

        int64 num_of_increased_S = bin_search(U, S, 1, O);

        U -= 2 * num_of_increased_S;
        S += num_of_increased_S;
    } 

    cout << cnt << '\n';
    return 0;
}