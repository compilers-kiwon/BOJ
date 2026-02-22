#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, M, S, p1, p2;

    cin >> N >> M >> S;

    p1 = M * S;
    p2 = (M + 1LL) * S * (100LL - N) / 100LL;
    cout << min(p1, p2) << '\n';

    return 0;
}