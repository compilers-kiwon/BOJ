#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)

#define NO_COLOR (0)
#define COLOR_1 (1)
#define COLOR_2 (2)
#define MAX_COLOR (3)

int N, M, grid[MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            cin >> grid[row][col];
        }
    }
}

int simulate(void) {
    int ret = 0;

    for (int row = 1; row <= N; row++) {
        int cnt[MAX_COLOR] = {0, };

        for (int col = 1; col <= M; col++) {
            if (grid[row][col] == NO_COLOR) {
                if (cnt[COLOR_1] != 0 || cnt[COLOR_2] != 0) {
                    ret += 1 + min(cnt[COLOR_1], cnt[COLOR_2]);
                    cnt[COLOR_1] = cnt[COLOR_2] = 0;
                }
            } else {
                if (grid[row][col-1] != grid[row][col]) {
                    cnt[grid[row][col]]++;
                }
            }
        }

        if (cnt[COLOR_1] != 0 || cnt[COLOR_2] != 0) {
            ret += 1 + min(cnt[COLOR_1], cnt[COLOR_2]);
            cnt[COLOR_1] = cnt[COLOR_2] = 0;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}