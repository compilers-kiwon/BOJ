#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define NUM_OF_TYPES (4)
#define NUM_OF_REACTIONS (5)

enum {
    WIN = 1,
    LOSE = 0,
};

typedef vector<int> State;

const State required[NUM_OF_REACTIONS] = {
    {2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}
};

int simulate(State cur, map<State, int>& dp) {
    auto it = dp.find(cur);

    if (it != dp.end()) {
        return it->second;
    }

    dp[cur] = LOSE;

    for (int i = 0; i< NUM_OF_REACTIONS; ++i) {
        State adj;
        bool impossible = false;

        for (int j = 0; j < cur.size(); ++j) {
            adj.push_back(cur[j] - required[i][j]);

            if (adj.back() < 0) {
                impossible = true;
                break;
            }
        }

        if (impossible == true) {
            continue;
        }

        if (simulate(adj, dp) == LOSE) {
            dp[cur] = WIN;
            break;
        }
    }

    return dp[cur];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        State s;
        map<State, int> dp;

        for (int j = 0; j < NUM_OF_TYPES; ++j) {
            int p;
            cin >> p;
            s.push_back(p);
        }

        if (simulate(s, dp) == WIN) {
            cout << "Patrick\n";
        } else {
            cout << "Roland\n";
        }
    }

    return 0;
}