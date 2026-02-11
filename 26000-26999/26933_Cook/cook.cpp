#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;

    for (cin >> N, sum = 0; N > 0; --N) {
        int H, B, K;
        cin >> H >> B >> K;
        sum += max(0, B - H) * K;
    }

    cout << sum << '\n';

    return 0;
}