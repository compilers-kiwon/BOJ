#include <iostream>

using namespace std;

#define MAX_SIZE (2000+1)

int clap_cnt[MAX_SIZE], sum[MAX_SIZE];

int count_clap(int from, int to) {
    return (sum[to] - sum[from-1]);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, A, max_cnt;

    cin>>N>>M;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            int Q;
            cin>>Q;
            clap_cnt[col] += Q;
        }
    }

    for (int i = 1; i <= M; i++) {
        sum[i] = sum[i-1] + clap_cnt[i];
    }

    cin>>A;
    max_cnt = 0;

    for (int col = 1; col <= ((M - A) + 1); col++) {
        max_cnt = max(max_cnt, count_clap(col, col + A - 1));
    }

    cout<<max_cnt<<'\n';
    return 0;
} 