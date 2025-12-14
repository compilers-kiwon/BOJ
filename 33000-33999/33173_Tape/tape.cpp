#include <iostream>

using namespace std;

#define MAX_SIZE (500+1)

int H, W, Q;
int grid[MAX_SIZE+1][MAX_SIZE+1];
bool masked[MAX_SIZE+1][MAX_SIZE+1];

void paint(int row, int col, int color) {
    for (int d_row = 0; d_row <= 1; d_row++) {
        for (int d_col = 0; d_col <= 1; d_col++) {
            int adj_row = row + d_row;
            int adj_col = col + d_col;

            if (masked[adj_row][adj_col] == true) {
                continue;
            }

            grid[adj_row][adj_col] = color;
        }
    }
}

void mask(int row, int col) {
    for (int d_row = 0; d_row <= 1; d_row++) {
        for (int d_col = 0; d_col <= 1; d_col++) {
            int adj_row = row + d_row;
            int adj_col = col + d_col;
            masked[adj_row][adj_col] = true;
        }
    }
}

void print(void) {
    for (int row = 1; row <= H; row++) {
        for (int col = 1; col <= W; col++) {
            cout << grid[row][col] << ((col==W)?'\n':' ');
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (cin >> H >> W >> Q; Q > 0; Q--) {
        int q, x, y, c;

        cin >> q;

        if (q == 1) {
            cin >> x >> y >> c;
            paint(x, y, c);
        } else {
            cin >> x >> y;
            mask(x, y);
        }
    }

    print();

    return 0;
}