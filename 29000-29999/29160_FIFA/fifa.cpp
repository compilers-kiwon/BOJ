#include <iostream>
#include <queue>

using namespace std;

#define NONE (-1)
#define NUM_OF_POSITIONS (11)

void build_team(priority_queue<int> players[], int player_list[]) {
    for (int p = 1; p <= NUM_OF_POSITIONS; p++) {
        if (player_list[p] == NONE) {
            continue;
        }

        players[p].push(player_list[p]);
        player_list[p] = NONE;
    }
}

void select_starting_players(priority_queue<int> players[], int player_list[]) {
    for (int p = 1; p <= NUM_OF_POSITIONS; p++) {
        if (players[p].empty()) {
            continue;
        }

        player_list[p] = players[p].top();
        players[p].pop();
    }
}

void decline(int player_list[]) {
    for (int p = 1; p <= NUM_OF_POSITIONS; p++) {
        if (player_list[p] == NONE) {
            continue;
        }

        player_list[p] = max(0, player_list[p]-1);
    }
}

int simulate(priority_queue<int> players[], int num_of_years) {
    int starting[NUM_OF_POSITIONS+1] = {NONE, };

    for (int y = 1; y <= num_of_years; y++) {
        // March
        select_starting_players(players, starting);

        // August
        decline(starting);

        // Initial
        build_team(players, starting);
    }

    int ret = 0;

    for (int p = 1; p <= NUM_OF_POSITIONS; p++) {
        ret += (players[p].empty())?0:players[p].top();
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    priority_queue<int> players[NUM_OF_POSITIONS + 1];

    cin>>N>>K;

    for (int i = 1; i <= N; i++) {
        int P, W;
        cin>>P>>W;
        players[P].push(W);
    }

    cout<<simulate(players, K)<<'\n';
    return 0;
}