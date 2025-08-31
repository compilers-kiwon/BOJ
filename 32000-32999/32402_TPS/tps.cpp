#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

enum {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    MAX_DIR = 4,
};

const struct {
    int dx, dy;
} adj[MAX_DIR] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

#define TURN_RIGHT(d) (((d)+1)%MAX_DIR)
#define TURN_LEFT(d) (((d)+3)%MAX_DIR)
#define CAM_OFFSET(d) (((d)+2)%MAX_DIR)

int get_move_dir(int cur_dir, char c) {
    int ret;

    switch (c) {
        case 'W': ret = cur_dir; break;
        case 'A': ret = TURN_LEFT(cur_dir); break;
        case 'S': ret = CAM_OFFSET(cur_dir); break;
        case 'D': ret = TURN_RIGHT(cur_dir); break;
        default: /* do nothing */; break;
    }

    return ret;
}

int simulate(const string& input, int cur_dir, int& x, int& y) {
    int ret;

    if (input == "MR") {
        ret = TURN_RIGHT(cur_dir);
    } else if (input == "ML") {
        ret = TURN_LEFT(cur_dir);
    } else {
        int move_dir = get_move_dir(cur_dir, input.front());
        ret = cur_dir;
        x += adj[move_dir].dx, y += adj[move_dir].dy;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, x, y, cur_dir;

    for (cin >> N, cur_dir = UP, x = y = 0; N > 0; N--) {
        string in;
        
        cin >> in;
        cur_dir = simulate(in, cur_dir, x, y);

        cout << x << ' ' << y << ' ';
        cout << x + adj[CAM_OFFSET(cur_dir)].dx << ' '
                << y + adj[CAM_OFFSET(cur_dir)].dy << '\n';
    }

    return 0;
}