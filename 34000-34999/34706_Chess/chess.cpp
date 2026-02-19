#include <iostream>

using namespace std;

void print_pos(int size) {
    for (int row = 1; row <= size; ++row) {
        cout << row << ' ' << (size + 1) / 2 << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; --T) {
        int N;
        cin >> N;
        print_pos(N);
    }

    return 0;
}