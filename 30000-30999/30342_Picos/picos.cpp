#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, T, K, ans;
    
    ans = 0;
    cin >> N >> M >> T >> K;

    for (; K > 0 && N != 0; K -= T, N = max(0, N - M)) {
        ans += K * min(M, N);
    }

    cout << ans << '\n';
    return 0;
}