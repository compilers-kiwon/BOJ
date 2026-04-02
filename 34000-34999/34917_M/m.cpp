#include <iostream>
#include <string>

using namespace std;

void simulate(int size) {
    for (int row = 0, h = 0, t = size - 1; row < size; ++row, ++h, --t) {
        string cur(size, '.');

        cur.front() = cur.back() = '#';

        if (h <= t) {
            cur[h] = cur[t] = '#';
        }

        cout << cur << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        simulate(N);
    }

    return 0;
}