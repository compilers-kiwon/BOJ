#include <iostream>

using namespace std;

#define TBD (-1)

#define MAX_NUM_OF_GAMES (100000+1)
#define MAX_NUM_OF_CHANGES (20)
#define NUM_OF_GESTURES (3)

#define get_gesture_num(c) ((c)=='H'?0:(c)=='P'?1:2)
#define cow_win(f,c) (((f)+1)%NUM_OF_GESTURES==(c))

int N, K, farmer_gesture[MAX_NUM_OF_GAMES];
int dp[MAX_NUM_OF_GAMES][NUM_OF_GESTURES][MAX_NUM_OF_CHANGES+1];

void input(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        char c;
        
        cin >> c;
        farmer_gesture[i] = get_gesture_num(c);

        for (int g = 0; g < NUM_OF_GESTURES; g++) {
            fill(&dp[i][g][0], &dp[i][g][K+1], TBD);
        }
    }
}

int get_dp(int cur_game_idx, int cur_gesture, int cur_num_of_changes) {
    int& ret = dp[cur_game_idx][cur_gesture][cur_num_of_changes];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int g = 0; g < NUM_OF_GESTURES; g++) {
        if (cur_gesture == g) {
            ret = max(ret, get_dp(cur_game_idx - 1, g, cur_num_of_changes));
        } else if (cur_num_of_changes > 0) {
            ret = max(ret, get_dp(cur_game_idx - 1, g, cur_num_of_changes - 1));
        }
    }

    return (ret += cow_win(farmer_gesture[cur_game_idx], cur_gesture));
}

int simulate(void) {
    int ret = 0;

    for (int g = 0; g < NUM_OF_GESTURES; g++) {
        for (int c = 0; c <= K; c++) {
            ret = max(ret, get_dp(N, g, c));
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