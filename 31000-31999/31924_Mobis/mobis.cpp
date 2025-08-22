#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)
#define FILAL_LEN (5)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int N;
char grid[MAX_SIZE][MAX_SIZE+1];

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];
    }
}

bool simulate(int cur_row, int cur_col, int d_row, int d_col) {
    char str[FILAL_LEN+1] = "MOBIS";

    for (int i = 0; i < FILAL_LEN; i++) {
        int adj_row = cur_row + (d_row * i);
        int adj_col = cur_col + (d_col * i);

        if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, N)) {
            return false;
        }

        if (str[i] != grid[adj_row][adj_col]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;

    input();

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            if (grid[row][col] != 'M') {
                continue;
            }

            for (int d_row = -1; d_row <= 1; d_row++) {
                for (int d_col = -1; d_col <= 1; d_col++) {
                    cnt += simulate(row, col, d_row, d_col)?1:0;
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}