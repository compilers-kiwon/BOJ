#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, W, ans;

    cin >> N >> W;
    ans = N * 10;

    if (N >= 3) {
        ans += 20;
    }

    if (N == 5) {
        ans += 50;
    }
    
    if (W > 1000) {
        ans = max(0, ans - 15);
    }

    cout << ans << '\n';

    return 0;
}