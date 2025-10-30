#include <iostream>

using namespace std;

#define MAX_SIZE (10)

enum {
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3,
    MAX_DIR = 4,
};

#define CHANGE_STATE(s) (((s)+2)%MAX_DIR)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int W, H, N, X, Y;
int state[MAX_SIZE][MAX_SIZE];
char grid[MAX_SIZE][MAX_SIZE+1];

void input(void) {
    cin >> W >> H >> N >> X >> Y;

    for (int row = 0; row < H; row++) {
        cin >> &grid[row][0];

        for (int col = 0; col < W; col++) {
            int& s = state[row][col];

            switch (grid[row][col]) {
                case '<': s = LEFT; break;
                case '>': s = RIGHT; break;
                case '^': s = UP; break;
                case 'v': s = DOWN; break;
                case '-': s = LEFT; break;
                case '|': s = UP; break;
                case '.':
                default:
                    s = MAX_DIR;
                    break;
            }
        }
    }
}

void simulate(int& col, int& row) {
    for (;;) {
        if (!IN_RANGE(0, col, W) || !IN_RANGE(0, row, H)) {
            break;
        }

        int d = state[row][col];

        if (d == MAX_DIR) {
            break;
        }

        if (grid[row][col] == '-' || grid[row][col] == '|') {
            state[row][col] = CHANGE_STATE(state[row][col]);
        }

        col += adj[d].d_col;
        row += adj[d].d_row;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int i = 1; i <= N; i++) {
        int cur_x, cur_y;

        cur_x = X, cur_y = Y;
        simulate(cur_x, cur_y);
        cout << cur_x << ' ' << cur_y << '\n';
    }

    return 0;
}