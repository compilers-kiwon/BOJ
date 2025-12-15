#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_SIZE (100+1)
#define INF (0x7FFFFFFF)

typedef pair<int, int> State; // <-cost, cur_pos>

int cost_table[MAX_SIZE][MAX_SIZE];
bool is_connected[MAX_SIZE][MAX_SIZE];
vector<int> connected[MAX_SIZE];

int simulate(int from, int to, int num_of_pos) {
    int ret = INF;
    priority_queue<State> pq;
    vector<int> dp(num_of_pos + 1, INF);

    for (pq.push({0, from}), dp[from] = 0; !pq.empty(); pq.pop()) {
        int cur_pos = pq.top().second;
        int cur_cost = -pq.top().first;

        if (cur_pos == to) {
            ret = min(ret, cur_cost);
            continue;
        }

        const vector<int>& adj = connected[cur_pos];

        for (int i = 0; i < adj.size(); i++) {
            int adj_pos = adj[i];
            int adj_cost = cost_table[cur_pos][adj_pos];

            if (cur_cost + adj_cost < dp[adj_pos]) {
                dp[adj_pos] = cur_cost + adj_cost;
                pq.push({-dp[adj_pos], adj_pos});
            }
        }
    }

    return ((ret==INF)?-1:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, k;

    for (cin >> n >> k; k > 0; k--) {
        int h, a, b, c, d, e;

        cin >> h;

        if (h == 0) {
            cin >> a >> b;
            cout << simulate(a, b, n) << '\n';
        } else { // h == 1
            cin >> c >> d >> e;
            cost_table[c][d] = (cost_table[c][d]==0)?e:min(e, cost_table[c][d]);
            cost_table[d][c] = cost_table[c][d];
            
            if (is_connected[c][d] == false) {
                is_connected[c][d] = true;
                connected[c].push_back(d), connected[d].push_back(c);
            }
        }
    }

    return 0;
}