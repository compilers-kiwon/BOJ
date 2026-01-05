#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE (10000+1)

int E[MAX_SIZE];

int simulate(int d, int K, int L) {
    int ret;

    if (d >= 2 * K) {
        ret = (d - (2 * K)) * L;
    } else {
        ret = (2 * K) - d;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int S, N, K, L;

    cin >> S >> N;

    for (int i =1; i <= N; i++) {
        cin >> E[i];
    }

    cin >> K >> L;

    int min_idx, min_hp;

    min_hp = 0x7FFFFFFF;

    for (int i = 1; i <= N; i++) {
        int h = simulate(abs(S - E[i]), K, L);

        if (h < min_hp) {
            min_hp = h, min_idx = i;
        }
    }

    cout << min_hp << ' ' << min_idx << '\n';

    return 0;
}