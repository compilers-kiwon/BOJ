#include <iostream>
#include <cmath>

using namespace std;

typedef long long int int64;

int64 get_cost(int64 required, int64 unit1,
                int64 price1, int64 unit2, int64 price2) {
    int64 min_cost = __INT64_MAX__;

    for (int64 i = 0; i < unit2; i++) {
        int64 cost = price1 * i;
        int64 remained = ((unit1*i)>=required)?0:
                            (required - (unit1 * i)) / unit2 +
                            (((required - (unit1 * i)) % unit2)==0?0:1);
        cost += remained * price2;
        min_cost = min(min_cost, cost);
    }

    return min_cost;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, A, B, C, D;

    cin >> N >> A >> B >> C >> D;
    cout << min(get_cost(N, A, B, C, D), 
                get_cost(N, C, D, A, B)) << '\n';

    return 0;
}