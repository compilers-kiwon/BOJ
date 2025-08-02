#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (100000)

int N, M, K, house[MAX_SIZE*2], sum[MAX_SIZE*2];

void get_sum(void) {
    sum[0] = house[0];

    for (int i = 1; i < M; i++) {
        sum[i] = sum[i-1] + house[i];
    }

    for (int h = 0, t = M; t < (2 * N); h++, t++) {
        sum[t] = sum[t-1] + house[t] - house[h];
    }
}

int count(void) {
    if (N == M) {
        return ((sum[N]<K)?1:0);
    }
    int ret = 0;

    for (int i = N; i < (2 * N); i++) {
        ret += (sum[i]<K)?1:0;
    }

    return ret;
}

void input(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> house[i];
        house[i+N] = house[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        input();
        get_sum();
        cout << count() << '\n';
    }

    return 0;
}