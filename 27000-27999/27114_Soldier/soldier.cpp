#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_ENERGY (1000000+1)
#define MAX_DIR (4)
#define TRUN_DIR(n,o) (((n)+(o))%MAX_DIR)

typedef tuple<int, int, int> State;

int dp[MAX_ENERGY][MAX_DIR], energy[MAX_DIR-1];

int simulate(int max_energy) {
    queue<State> q;
    const int offset[MAX_DIR-1] = {1, 3, 2}; // {left, right, around}

    for (q.push({0, 0, 0}); !q.empty(); q.pop()){
        auto [cur_energy, cur_dir, cur_num] = q.front();

        if (cur_energy == max_energy) {
            continue;
        }

        for (int i = 0; i < (MAX_DIR - 1); i++) {
            int next_energy = cur_energy + energy[i];
            int next_dir = TRUN_DIR(cur_dir, offset[i]);
            int next_num = cur_num + 1;

            if (next_energy > max_energy) {
                continue;
            }

            if (dp[next_energy][next_dir] == 0 ||
                    next_num < dp[next_energy][next_dir]) {
                dp[next_energy][next_dir] = next_num;
                q.push({next_energy, next_dir, next_num});
            }
        }
    }

    return ((dp[max_energy][0]==0)?-1:dp[max_energy][0]);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;
    int& A = energy[0];
    int& B = energy[1];
    int& C = energy[2];

    cin >> A >> B >> C >> K;
    cout << simulate(K) << '\n';

    return 0;
}