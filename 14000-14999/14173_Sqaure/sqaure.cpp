#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x1[2], y1[2], x2[2], y2[2];

    for (int i = 0; i < 2; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    int left = min(x1[0], x1[1]);
    int bottom = min(y1[0], y1[1]);
    int right = max(x2[0], x2[1]);
    int top = max(y2[0], y2[1]);
    int s = max(right - left, top - bottom);

    cout << s * s << '\n';

    return 0;
}