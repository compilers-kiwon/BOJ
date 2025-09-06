#include <iostream>

using namespace std;

typedef long long int int64;

int64 get_num_of_ornaments(int64 n) {
    int64 a, ret;

    a = ret = 0;

    for (int64 i = 1; i <= n; i++) {
        a = a + i;
        ret += a;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n >0; n--) {
        int64 layer;
        cin >> layer;
        cout << get_num_of_ornaments(layer) << '\n';
    }

    return 0;
}