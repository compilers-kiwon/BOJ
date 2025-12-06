#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double H, W, N, M;
    cin >> H >> W >> N >> M;
    cout << (int)(ceil(H / (N + 1)) * ceil(W / (M + 1))) << '\n';

    return 0;
}