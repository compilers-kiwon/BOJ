#include <iostream>

using namespace std;

#define CANCER_SIZE (2)
#define MAX_SIZE (1000)

char grid[MAX_SIZE+2][MAX_SIZE+2+1];

bool is_cancer(int row, int col) {
    for (int d_row = 0; d_row < CANCER_SIZE; ++d_row) {
        for (int d_col = 0; d_col < CANCER_SIZE; ++d_col) {
            if (grid[row+d_row][col+d_col] != '1') {
                return false;
            }
        }
    }

    return true;
}

bool find_cancer(int row_size, int col_size) {
    for (int row = 1; row <= row_size; ++row) {
        for (int col = 1; col <= col_size; ++col) {
            if (is_cancer(row, col) == true) {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    for (int row = 1; row <= N; ++row) {
        cin >> &grid[row][1];
    }

    cout << (find_cancer(N, M)?1:0) << '\n';

    return 0;
}