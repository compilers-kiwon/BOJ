#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int H, M;
    cin >> H >> M;
    cout << (H * 60) + M << '\n';

    return 0;
}