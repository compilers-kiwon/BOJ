#include <iostream>

using namespace std;

#define TBD (-1)
#define MAX_SIZE (1000+1)
#define NUM_OF_MILKS (3)
#define PREV_MILK(cur) (((cur)+NUM_OF_MILKS-1)%NUM_OF_MILKS)

int N, grid[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][NUM_OF_MILKS];

int simulate(void) {
    for (int col = 2; col <= N; ++col) {
        for (int m = 0; m < NUM_OF_MILKS; ++m) {
            dp[1][col][m] = dp[1][col-1][m];
        }

        int cur_milk = grid[1][col];

        if (dp[1][col][0] == 0 && cur_milk == 0) {
            dp[1][col][0] = 1;
            continue;
        }

        int prev_milk = PREV_MILK(cur_milk);

        if (dp[1][col][prev_milk] != 0) {
            dp[1][col][cur_milk] =
                max(dp[1][col][cur_milk], dp[1][col][prev_milk] + 1);
        }
    }

    for (int row = 2; row <= N; ++row) {
        for (int m = 0; m < NUM_OF_MILKS; ++m) {
            dp[row][1][m] = dp[row-1][1][m];
        }

        int cur_milk = grid[row][1];

        if (dp[row][1][0] == 0 && cur_milk == 0) {
            dp[row][1][0] = 1;
            continue;
        }

        int prev_milk = PREV_MILK(cur_milk);

        if (dp[row][1][prev_milk] != 0) {
            dp[row][1][cur_milk] =
                max(dp[row][1][cur_milk], dp[row][1][prev_milk] + 1);
        }
    }

    for (int row = 2; row <= N; ++row) {
        for (int col = 2; col <= N; ++col) {
            for (int m = 0; m < NUM_OF_MILKS; ++m) {
                dp[row][col][m] = max(dp[row-1][col][m], dp[row][col-1][m]);
            }

            int cur_milk = grid[row][col];

            if (dp[row][col][0] == 0 && cur_milk == 0) {
                dp[row][col][0] = 1;
                continue;
            }

            int prev_milk = PREV_MILK(cur_milk);

            if (dp[row][col][prev_milk] != 0) {
                dp[row][col][cur_milk] =
                    max(dp[row][col][cur_milk], dp[row][col][prev_milk] + 1);
            }
        }
    }

    int ret = 0;

    for (int m = 0; m < NUM_OF_MILKS; ++m) {
        ret = max(ret, dp[N][N][m]);
    }

    return ret;
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col) {
            cin >> grid[row][col];
            fill(&dp[row][col][0], &dp[row][col][NUM_OF_MILKS], TBD);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    fill(&dp[1][1][0], &dp[1][1][NUM_OF_MILKS], 0);
    
    dp[1][1][0] = (grid[1][1]==0)?1:0;
    cout << simulate() << '\n';

    return 0;
}