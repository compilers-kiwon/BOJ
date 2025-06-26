#include <iostream>
#include <unordered_map>

#define MAX_SIZE (100+1)

const int EMPTY = 0;
const int ITEM = 1;
const int BLOCKED = 2;

int N, M, A, B, grid[MAX_SIZE][MAX_SIZE];
std::unordered_map<int, int> dp[MAX_SIZE][MAX_SIZE];

void input(void) {
    std::cin>>N>>M>>A>>B;

    for (int i = 1; i <= A; i++) {
        int row, col;

        std::cin>>row>>col;
        grid[row][col] = ITEM;
    }

    for (int i = 1; i <= B; i++) {
        int row, col;

        std::cin>>row>>col;
        grid[row][col] = BLOCKED;
    }
}

int get_dp(int row, int col, int num_of_items) {
    if (dp[row][col].find(num_of_items) != dp[row][col].end()) {
        return dp[row][col][num_of_items];
    }

    dp[row][col][num_of_items] = 0;

    // prev left
    if (col - 1 > 0 && grid[row][col-1] != BLOCKED) {
        dp[row][col][num_of_items] += get_dp(row, col - 1, num_of_items - grid[row][col]);
    }

    // prev up
    if (row - 1 > 0 && grid[row-1][col] != BLOCKED) {
        dp[row][col][num_of_items] += get_dp(row - 1, col, num_of_items - grid[row][col]);
    }

    return dp[row][col][num_of_items];
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    input();
    dp[1][1][grid[1][1]] = 1;

    std::cout<<get_dp(N, M, A)<<'\n';

    return 0;
}