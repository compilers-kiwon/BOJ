#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M, H, N, sum;

    for (cin >> M >> H >> N, sum = 0; N > 0; --N) {
        int C, B;
        cin >> C >> B;
        sum += max(M *C, H * B);
    }

    cout << sum << '\n';

    return 0;
}