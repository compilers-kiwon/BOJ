#include <iostream>

using namespace std;

#define MSB_POS (63)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef long long int int64;

int get_msb_pos(int64 num) {
    int ret;

    for (int i = MSB_POS; i >= 0; i--) {
        if (num & (1LL << i)) {
            ret = i;
            break;
        }
    }

    return ret;
}

int64 get_num(int64 base, int lower, int upper, int64 min_num, int64 max_num) {
    int64 ret;

    for (int i = lower; i <= upper; i++) {
        ret = base + (1LL << i);

        if (IN_RANGE(min_num, ret, max_num)) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 a, b;
    int a_msb_pos, b_msb_pos;

    cin >> a >> b;

    if (a == b) {
        cout << a << '\n';
        return 0;
    }

    a_msb_pos = get_msb_pos(a);
    b_msb_pos = get_msb_pos(b);

    if (a_msb_pos < b_msb_pos) {
        int64 num = get_num(0LL, a_msb_pos, b_msb_pos, a, b);
        cout << num << '\n';
        return 0;
    }

    // a_msb_pos == b_msb_pos
    int64 num = 0;

    for (int lower = 0, upper = b_msb_pos;;upper--) {
        for (int i = lower; i <= upper; i++) {
            int64 cur = num + (1LL << i);

            if (IN_RANGE(a, cur, b)) {
                cout << cur << '\n';
                return 0;
            }
        }

        if ((num + (1LL << upper)) <= b) {
            num += (1LL << upper);
        }
    }

    return 0;
}