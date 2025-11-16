#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int W, N;
    cin >> W >> N;
    cout << (W * 5280) / N << '\n';

    return 0;
}