#include <iostream>

using namespace std;

#define MAX_NUM (9)
#define TOTAL_SIZE (9)
#define REGION_SIZE (3)

int grid[TOTAL_SIZE][TOTAL_SIZE];

bool check_grid(int s_row, int s_col, int row_size, int col_size) {
    bool used[MAX_NUM+1];

    fill(used, used + MAX_NUM + 1, false);

    for (int d_row = 0; d_row < row_size; d_row++) {
        for (int d_col = 0; d_col < col_size; d_col++) {
            int row = s_row + d_row;
            int col = s_col + d_col;

            if (used[grid[row][col]] == true) {
                return false;
            }

            used[grid[row][col]] = true;
        }
    }

    return true;
}

bool check_sudoku(void) {
    // 1. each row
    for (int row = 0; row < TOTAL_SIZE; row++) {
        if (check_grid(row, 0, 1, TOTAL_SIZE) == false) {
            return false;
        }
    }

    // 2. each col
    for (int col = 0; col < TOTAL_SIZE; col++) {
        if (check_grid(0, col, TOTAL_SIZE, 1) == false) {
            return false;
        }
    }

    // 3. each region
    for (int row = 0; row < TOTAL_SIZE; row += REGION_SIZE) {
        for (int col = 0; col < TOTAL_SIZE; col += REGION_SIZE) {
            if (check_grid(row, col, REGION_SIZE, REGION_SIZE) == false) {
                return false;
            }
        }
    }

    return true;
}

void input(void) {
    for (int row = 0; row < TOTAL_SIZE; row++) {
        for (int col = 0; col < TOTAL_SIZE; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << (check_sudoku()?"VALID":"INVALID!") << '\n';

    return 0;
}