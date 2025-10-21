#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE (1<<10)
#define WINNER_POS (1)

int N, grid[MAX_SIZE][MAX_SIZE];

int solve(int row, int col, int cur_size) {
    if (cur_size == 1) {
        return grid[row][col];
    }

    vector<int> numbers;
    int next_size = cur_size / 2;

    for (int row_offset = 0; row_offset <= 1; row_offset++) {
        for (int col_offset = 0; col_offset <= 1; col_offset++) {
            numbers.push_back(solve(row + (next_size * row_offset),
                                    col + (next_size * col_offset),
                                    next_size));
        }
    }

    sort(numbers.begin(), numbers.end());
    return numbers[WINNER_POS];
}

void input(void) {
    cin >> N;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << solve(0, 0, N) << '\n';

    return 0;
}