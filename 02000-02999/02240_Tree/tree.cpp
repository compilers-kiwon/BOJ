#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_TIME (1000+1)
#define NUM_OF_TREES (2)
#define MAX_POWER (30+1)

#define get_next_tree(t) ((t)==1?2:1)

typedef struct {
    int time, tree, power, fruits;
} State;

int T, W, tree[MAX_TIME];
int dp[MAX_TIME][NUM_OF_TREES+1][MAX_POWER];

void input(void) {
    cin>>T>>W;

    for (int t = 1; t <= T; t++) {
        cin>>tree[t];
    }

    memset(dp, -1, sizeof(dp));
}

int gather_fruits(void) {
    int ret = 0;
    State init_state = {1, 1, W, 0};
    queue<State> q;

    for (q.push(init_state); !q.empty(); q.pop()) {
        State cur = q.front();

        if (cur.time > T) {
            ret = max(ret, cur.fruits);
            continue;
        }

        if (cur.fruits <= dp[cur.time][cur.tree][cur.power]) {
            continue;
        }

        dp[cur.time][cur.tree][cur.power] = cur.fruits;

        // stay
        State stay = {cur.time + 1, cur.tree, cur.power,
                        cur.fruits + ((tree[cur.time]==cur.tree)?1:0)};
        q.push(stay);

        // move
        if (cur.power <= 0) {
            continue;
        }

        State move = {cur.time + 1, get_next_tree(cur.tree), cur.power - 1,
                        cur.fruits + ((tree[cur.time]==get_next_tree(cur.tree))?1:0)};
        q.push(move);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<gather_fruits()<<'\n';
    
    return 0;
}