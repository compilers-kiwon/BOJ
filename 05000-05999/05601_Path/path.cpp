#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (16+1)

int a, b, grid[MAX_SIZE][MAX_SIZE];

void input(void) {
    int n;

    cin >> a >> b;

    for (int row = 1; row <= b; row++) {
        for (int col = 1; col <= a; col++) {
            grid[row][col] = TBD;
        }
    }

    for (cin >> n; n > 0; n--) {
        int x, y;
        cin >> x >> y;
        grid[y][x] = 0;
    }
}

int get_num_of_path(int row, int col) {
    int& ret = grid[row][col];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    if (row - 1 >= 1) {
        ret += get_num_of_path(row - 1, col);
    }

    if (col - 1 >= 1) {
        ret += get_num_of_path(row, col - 1);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    grid[1][1] = 1;
    cout << get_num_of_path(b, a) << '\n';

    return 0;
}