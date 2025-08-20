#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (100000+1)
#define NONE (0)

typedef pair<int, pair<int, int>> Log;

int seat_status[MAX_SIZE], my_seat[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, C, K;
    priority_queue<Log> log_q;

    cin >> X >> C >> K;

    for (int i = 1; i <= K; i++) {
        int T, S, N;
        cin >> T >> S >> N;
        log_q.push({-T, {S, N}});
    }

    for (; !log_q.empty(); log_q.pop()) {
        int seat_number = log_q.top().second.first;
        int sutdent_number = log_q.top().second.second;
        
        if (seat_status[seat_number] != NONE) {
            continue;
        }

        if (my_seat[sutdent_number] != NONE) {
            seat_status[my_seat[sutdent_number]] = NONE;
        }

        my_seat[sutdent_number] = seat_number;
        seat_status[seat_number] = sutdent_number;
    }

    for (int i = 1; i <= X; i++) {
        if (my_seat[i] == NONE) {
            continue;
        }

        cout << i << ' ' << my_seat[i] << '\n';
    }

    return 0;
}