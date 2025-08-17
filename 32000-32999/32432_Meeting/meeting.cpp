#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K, ans;
    cin >> N >> K;

    for (int i = 0;; i++) {
        if (((N * i) + (N - 1)) > K) {
            break;
        }

        ans = i;
    }

    cout << ans << '\n';
    return 0;
}