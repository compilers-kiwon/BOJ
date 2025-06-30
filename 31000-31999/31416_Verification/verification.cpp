#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)

int simulate(int Ta, int Tb, int Va, int Vb) {
    int dh = Tb * Vb;
    int sh = Ta * Va;
    int ret = max(dh, sh);

    for (int i = 1; i <= Va; i++) {
        ret = min(ret, max(dh + (Ta * i), (Va - i) * Ta));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;

    cin>>Q;

    for (int i = 1; i <= Q; i++) {
        int Ta, Tb, Va, Vb;

        cin>>Ta>>Tb>>Va>>Vb;
        cout<<simulate(Ta, Tb, Va, Vb)<<'\n';
    }

    return 0;
}