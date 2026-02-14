#include <iostream>

using namespace std;

typedef long long int int64;

int simulate(int64 target) {
    int ret = 1;
    for (int64 cur = 1LL; cur < target; ++ret, cur *= 2LL) {};
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N;
    cin >> N;
    cout << (N==0LL?0LL:simulate(N)) << '\n';

    return 0;
}