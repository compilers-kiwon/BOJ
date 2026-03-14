#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, W, H, L;
    cin >> N >> W >> H >> L;
    cout << min(N, (W / L) * (H /L)) << '\n';

    return 0;
}