#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int W, H, A;

    cin >> W >> H;
    A = W * H * 10 / 2;
    cout << A / 10 << '.' << A % 10 << '\n';

    return 0;
}