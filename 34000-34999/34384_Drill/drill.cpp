#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double cur;

    cin >> cur;

    for (double t = 0.0f;; t += 3600.0f) {
        if (t > cur) {
            cout << ceil((t - cur) / 60.0f) << '\n';
            break;
        }
    }

    return 0;
}