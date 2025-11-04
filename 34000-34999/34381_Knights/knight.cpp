#include <iostream>
#include <cmath>

using namespace std;

#define NUM_OF_DIFFS (2)

const pair<int, int> diff[NUM_OF_DIFFS] = {
    {1, 2}, {2, 1}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char row;
    int col;

    cin >> row >> col;

    for (char r = 'a'; r <= 'h'; r++) {
        for (int c = 1; c <= 8; c++) {
            bool matched = false;

            for (int i = 0; i < NUM_OF_DIFFS; i++) {
                int d_row = abs(row - r);
                int d_col = abs(col - c);

                if (diff[i].first == d_row && diff[i].second == d_col) {
                    matched = true;
                    break;
                }
            }

            if (matched == true) {
                cout << r << c << '\n';
            }
        }
    }

    return 0;
}