#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_SIZE (300+1)

typedef pair<int, int> State; // <city, rank>
typedef pair<int, int> Path; // <to, score>

int N, M, K;
int dp[MAX_SIZE][MAX_SIZE];
vector<Path> connected[MAX_SIZE];
bool is_queued[MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= K; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;

        if (a > b) {
            continue;
        }
        
        connected[a].push_back({b, c});
    }
}

int simulate(void) {
    int ret = 0;
    queue<State> q;

    q.push({1, 1}), is_queued[1][1] = true, dp[1][1] = 0;

    for (; !q.empty();) {
        int cur_city = q.front().first;
        int cur_rank = q.front().second;
        int cur_score = dp[cur_city][cur_rank];

        q.pop(), is_queued[cur_city][cur_rank] = false;

        if (cur_city == N) {
            ret = max(ret, cur_score);
            continue;
        }

        if (cur_rank == M) {
            continue;
        }

        const vector<Path>& adj = connected[cur_city];

        for (int i = 0; i < adj.size(); i++) {
            int adj_city = adj[i].first;
            int adj_score = adj[i].second;

            if ((cur_score + adj_score) > dp[adj_city][cur_rank+1]) {
                if (is_queued[adj_city][cur_rank+1] == false) {
                    q.push({adj_city, cur_rank + 1});
                    is_queued[adj_city][cur_rank+1] = true;
                }

                dp[adj_city][cur_rank+1] = cur_score + adj_score;
            }
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