#include <iostream>

using namespace std;

#define MAX_SIZE (1000+1)

int rect[MAX_SIZE][MAX_SIZE];

void fill_rect(int row, int col, int row_size, int col_size) {
    int num = 1;

    for (int d_row = 0; d_row < row_size; ++d_row) {
        for (int d_col = 0; d_col < col_size; ++d_col) {
            rect[row+d_row][col+d_col] = num++;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    fill_rect(1, 1, N / 2, M / 2);

    for (int row = 1; row <= N / 2; ++row) {
        int d_col = 1;

        for (int col = (M / 2) + 1; col <= M; ++col, d_col += 2) {
            rect[row][col] = rect[row][col-d_col];
        }
    }

    for (int col = 1; col <= M / 2; ++col) {
        int d_row = 1;

        for (int row = (N / 2) + 1; row <= N; ++row, d_row += 2) {
            rect[row][col] = rect[row-d_row][col];
        }
    }

    for (int row = (N / 2) + 1; row <= N; ++row) {
        int d_col = 1;

        for (int col = (M / 2) + 1; col <= M; ++col, d_col += 2) {
            rect[row][col] = rect[row][col-d_col];
        }
    }

    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= M; ++col) {
            cout << rect[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}