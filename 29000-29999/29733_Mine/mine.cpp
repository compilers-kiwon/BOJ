#include <iostream>

using namespace std;

#define MINE (-1)
#define MAX_SIZE (100+1)

int R, C, H;
int cnt[MAX_SIZE][MAX_SIZE][MAX_SIZE+1];
char cube[MAX_SIZE][MAX_SIZE][MAX_SIZE+1];

void input(void) {
    cin >> R >> C >> H;

    for (int h = 1; h <= H; ++h) {
        for (int r = 1; r <= R; ++r) {
            cin >> &cube[h][r][1];
        }
    }
}

void simulate(void) {
    for (int h = 1; h <= H; ++h) {
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                if (cube[h][r][c] == '.') {
                    continue;
                }

                for (int d1 = -1; d1 <= 1; ++d1) {
                    int adj_h = h + d1;

                    if (!(1 <= adj_h && adj_h <= H)) {
                        continue;
                    }

                    for (int d2 = -1; d2 <= 1; ++d2) {
                        int adj_r = r + d2;

                        if (!(1 <= adj_r && adj_r <= R)) {
                            continue;
                        }

                        for (int d3 = -1; d3 <= 1; ++d3) {
                            int adj_c = c + d3;

                            if (!(1 <= adj_c && adj_c <= C)) {
                                continue;
                            }

                            ++cnt[adj_h][adj_r][adj_c];
                        }
                    }
                }
            }
        }
    }
}

void print(void) {
    for (int h = 1; h <= H; ++h) {
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                if (cube[h][r][c] == '*') {
                    cout << '*';
                } else {
                    cout << cnt[h][r][c] % 10;
                }
            }

            cout << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return 0;
}