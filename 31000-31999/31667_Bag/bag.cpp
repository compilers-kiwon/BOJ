#include <iostream>

using namespace std;

typedef long long int int64;

#define INF (1000000LL*1000000LL*1000000LL)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 T, N1, N2, S1, S2, B;
    cin >> T >> N1 >> N2 >> S1 >> S2, B = INF;

    for (int64 num_of_item2 = 1LL; num_of_item2 <= 4LL; ++num_of_item2) {
        if (num_of_item2 > N2 || (num_of_item2 * S2) > T) {
            continue;
        }

        int64 cnt = 0LL;

        for (int64 n1 = N1, n2 = N2; n1 > 0 || n2 > 0; ++cnt) {
            int64 space_for_num_of_items1 = T - (max(0LL, min(n2, num_of_item2)) * S2);
            int64 num_of_item1 = space_for_num_of_items1 / S1;
            n2 -= num_of_item2, n1 -= num_of_item1;
        }
        
        B = min(B, cnt);
    }

    cout << B << '\n';

    return 0;
}