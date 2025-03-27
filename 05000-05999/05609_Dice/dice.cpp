#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define NUM_OF_SIDES (6)
#define TOP_SIDE (1)

enum {
    NORTH = 0,
    EAST,
    WEST,
    SOUTH,
    RIGHT,
    LEFT,
    MAX_DIR
};

const int rotated[MAX_DIR][NUM_OF_SIDES+1] = {
    {0, 2, 6, 3, 4, 1, 5}, // rotated by North
    {0, 4, 2, 1, 6, 5, 3}, // rotated by East
    {0, 3, 2, 6, 1, 5, 4}, // rotated by West
    {0, 5, 1, 3, 4, 6, 2}, // rotated by South
    {0, 1, 3, 5, 2, 4, 6}, // rotated by Right
    {0, 1, 4, 2, 5, 3, 6}, // rotated by Left
};

void rotate_dice(int cur_state[], int dir) {
    int tmp[NUM_OF_SIDES+1];

    for (int i = 1; i <= NUM_OF_SIDES; i++) {
        tmp[i] = cur_state[rotated[dir][i]];
    }

    copy(&tmp[1], &tmp[NUM_OF_SIDES+1], &cur_state[1]);
}

int get_dir(const string& s) {
    int ret;

    if (s == "North") {
        ret = NORTH;
    } else if (s == "East") {
        ret = EAST;
    } else if (s == "West") {
        ret = WEST;
    } else if (s == "South") {
        ret = SOUTH;
    } else if (s == "Right") {
        ret = RIGHT;
    } else { // s == Left
        ret = LEFT;
    }

    return ret;
}

int simulate(void) {
    int N, ret;
    int dice[NUM_OF_SIDES+1] = {0, 1, 2, 3, 4, 5, 6};

    cin>>N;
    ret = dice[TOP_SIDE];

    for (int i = 1; i <= N; i++) {
        string str;

        cin>>str;
        rotate_dice(dice, get_dir(str));
        ret += dice[TOP_SIDE];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout<<simulate()<<'\n';
    return 0;
}