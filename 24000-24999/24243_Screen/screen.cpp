#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)

int h, w, n;
char cur_screen[MAX_SIZE][MAX_SIZE];
char station[MAX_SIZE][MAX_SIZE][MAX_SIZE+1];

void input(void) {
    cin >> h >> w >> n;

    for (int i = 1; i <= n; i++) {
        for (int row = 1; row <= h; row++) {
            cin >> &station[i][row][1];
        }
    }

    for (int row = 1; row <= h; row++) {
        cin >> &cur_screen[row][1];
    }
}

int check_screen(int st) {
    for (int row = 1; row <= h; row++) {
        for (int col = 1; col <= w; col++) {
            if (station[st][row][col] == '.'
                    && cur_screen[row][col] == 'x') {
                return 0;
            }
        }
    }

    return 1;
}

bool simulate(void) {
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        cnt += check_screen(i);
    }

    return (cnt == 1);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << (simulate()?"yes":"no") << '\n';

    return 0;
}