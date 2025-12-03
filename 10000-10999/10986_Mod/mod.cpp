#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_MOD (1000)
#define MAX_SIZE (1000000+1)

int64 N, M, num_sum[MAX_SIZE], mod_sum[MAX_SIZE], mod_cnt[MAX_MOD];

void input(void) {
    cin >> N >> M;

    for (int64 i = 1; i <= N; i++) {
        int64 A;

        cin >> A;
        
        num_sum[i] = num_sum[i-1] + A;
        mod_sum[i] = num_sum[i] % M;
        mod_cnt[mod_sum[i]]++;
    }
}

int64 simulate(void) {
    int64 ret = mod_cnt[0];

    for (int64 i = 0; i < M; i++) {
        ret += ((mod_cnt[i] - 1) * mod_cnt[i]) / 2;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}