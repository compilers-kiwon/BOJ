#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define INF (10000)
#define MAX_SIZE (3000+1)

int p, t;
string state;
int from_left[MAX_SIZE], from_right[MAX_SIZE];

void count_infection(int from, int to, int step, int table[]) {
    int infected_pos = INF;

    for (int i = from; i != to; i += step) {
        switch (state[i]) {
            case 'I': infected_pos = i; break;
            case 'W': infected_pos = INF; break;
            case 'H': 
                table[i] = (infected_pos==INF)?INF:abs(i-infected_pos);
                break;
            default : break;
        }
    }
}

void init(void) {
    count_infection(0, state.length(), 1, from_left);
    count_infection(state.length() - 1, 0 - 1, -1, from_right);
}

int simulate(void) {
    int ret = 0;

    for (int i = 0; i < state.length(); i++) {
        if (state[i] != 'H') {
            continue;
        }

        if (from_left[i] == INF && from_right[i] == INF) {
            return 0;
        }

        ret = max(ret, min(from_left[i] * p, from_right[i] * p));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int time;

    cin >> p >> t >> state;
    init();
    time = simulate();

    if (time == 0 || time >= t) {
        cout << "CURED\n";
    } else {
        cout << "ALL INFECTED\n";
    }

    return 0;
}