#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (100)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K, N, M, cnt[MAX_NUM+1],ans;

    cin >> K, ans = 0;
    fill(&cnt[1], &cnt[MAX_NUM+1], 0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int A;

        cin >> A;
        
        if (A + K <= MAX_NUM) {
            cnt[A+K]++;
        }
    }

    cin >> M;

    for (int i = 1; i <= M; i++) {
        int B;
        cin >> B;
        ans += cnt[B];
    }

    cout << ans << '\n';

    return 0;
}