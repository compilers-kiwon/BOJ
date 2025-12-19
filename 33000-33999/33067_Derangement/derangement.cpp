#include <iostream>

using namespace std;

#define TBD (-1LL)
#define MAX_LEN (16)
#define MAX_SIZE (1<<MAX_LEN)

typedef long long int int64;

int N, a[MAX_LEN], b[MAX_LEN];
int64 dp[MAX_SIZE][MAX_LEN];

int64 get_dp(int used, int pos) {
    if (pos == -1) {
        return 1;
    }

    int64& ret = dp[used][pos];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int bit_pos = 0; bit_pos < N; bit_pos++) {
        if (bit_pos == a[pos] || bit_pos == b[pos]) {
            continue;
        }

        if (used & (1 << bit_pos)) {
            ret += get_dp(used - (1 << bit_pos), pos - 1);
        }
    }

    return ret;
}

int64 get_num(void) {
    int cur_num = (1 << N) - 1;
    int cur_pos = N - 1;
    int64 ret = 0;

    for (int bit_pos = 0; bit_pos < N; bit_pos++) {
        if (bit_pos == a[cur_pos] || bit_pos == b[cur_pos]) {
            continue;
        }

        ret += get_dp(cur_num - (1 << bit_pos), cur_pos - 1);
    }

    return ret;
}

void input(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
    }

    fill(&dp[0][0], &dp[0][0] + (MAX_SIZE * MAX_LEN), TBD);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        input();
        cout << get_num() << '\n';
    }

    return 0;
}