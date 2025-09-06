#include <iostream>

using namespace std;

#define MAX_NUM_OF_DOGS (100+1)
#define MAX_NUM_OF_DAYS (10000+1)
#define MATTED (-2)

int N, M, period[MAX_NUM_OF_DOGS], state[MAX_NUM_OF_DOGS], plan[MAX_NUM_OF_DAYS];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> period[i];
        state[i] = period[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> plan[i];
    }
}

void simulate(void) {
    for (int day = 1; day <= M; day++) {
        int cur_dog = plan[day];

        for (int i = 1; i <= N; i++) {
            if (i == cur_dog) {
                continue;
            }

            if (state[i] > 1) {
                state[i]--;
            } else if (state[i] == 1) {
                state[i] = MATTED;
            } else {
                state[i] = max(state[i] - 1, MATTED);
            }
        }

        if (++state[cur_dog] >= 0) {
            state[cur_dog] = period[cur_dog];
        }
    }
}

int get_num_of_matted_dogs(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        ret += (state[i]<0)?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    cout << get_num_of_matted_dogs() << '\n';

    return 0;
}