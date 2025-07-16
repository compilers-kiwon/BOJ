#include <iostream>

using namespace std;

#define MAX_NUM_OF_PIPES (100+1)
#define MAX_REQUIRED_SIZE (10000)
#define TBD (-1)

typedef pair<int, int> Pipe; // <Size, Number>

int N, x;
Pipe p[MAX_NUM_OF_PIPES];
int dp[MAX_NUM_OF_PIPES][MAX_REQUIRED_SIZE+1];

int get_dp(int required_size, int cur_pipe_idx) {
    if (required_size == 0) { 
        return 1;
    }

    if (cur_pipe_idx == 0) {
        return 0;
    }

    int& ret = dp[cur_pipe_idx][required_size];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    int pipe_size = p[cur_pipe_idx].first;
    int num_of_pipes = p[cur_pipe_idx].second;

    for (int num_of_used = 0; num_of_used <= num_of_pipes; num_of_used++) {
        int cur_size = num_of_used * pipe_size;

        if (cur_size > required_size) {
            break;
        }

        ret += get_dp(required_size - cur_size, cur_pipe_idx - 1);
    }

    return ret;
}

void input(void) {
    cin >> N >> x;

    for (int i = 1; i <= N; i++) {
        cin >> p[i].first >> p[i].second;
        fill(&dp[i][0], &dp[i][x+1], TBD);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << get_dp(x, N) << '\n';

    return 0;
}