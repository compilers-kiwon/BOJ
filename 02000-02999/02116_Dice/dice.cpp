#include <iostream>

using namespace std;

#define MAX_NUM (10000+1)
#define NUM_OF_LOCATIONS (6)
#define NUM_OF_DICE_SIDES (6)

typedef pair<int,int> Location; // <top, bottom>

const int MIN_DICE_NUM = 1;
const int MAX_DICE_NUM = 6;

const Location loc[NUM_OF_LOCATIONS] = {
    {6, 1}, {1, 6}, {3, 5}, {5, 3}, {4,2}, {2, 4}
};

int N, dice[MAX_NUM][NUM_OF_DICE_SIDES+1];

int get_bottom_side(int cur_dice, int number) {
    int side;

    for (side = 1; side <= NUM_OF_DICE_SIDES; side++) {
        if (dice[cur_dice][side] == number) {
            break;
        }
    }

    return side;
}

int get_top_side(int bottom_side) {
    int ret;

    for (int i = 0; i < NUM_OF_LOCATIONS; i++) {
        int t = loc[i].first;
        int b = loc[i].second;

        if (b == bottom_side) {
            ret = t;
            break;
        }
    }

    return ret;
}

int stack_dice(int cur_dice, int prev_top_number) {
    if (cur_dice > N) {
        return 0;
    }

    int bottom_side = get_bottom_side(cur_dice, prev_top_number);
    int top_side = get_top_side(bottom_side);

    int max_side_num = 0;

    for (int i = 1; i <= NUM_OF_DICE_SIDES; i++) {
        if (i == bottom_side || i == top_side) {
            continue;
        }

        max_side_num = max(max_side_num, dice[cur_dice][i]);
    }

    return (max_side_num + stack_dice(cur_dice + 1, dice[cur_dice][top_side]));
}

void input(void) {
    cin>>N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= NUM_OF_DICE_SIDES; j++) {
            cin>>dice[i][j];
        }
    }
}

int simulate(void) {
    int ret = 0;

    for (int bottom_num = MIN_DICE_NUM; bottom_num <= MAX_DICE_NUM; bottom_num++) {
        ret = max(ret, stack_dice(1, bottom_num));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return 0;
}