#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF (0x7FFFFFFF)

typedef pair<string, int> Path;
typedef pair<int, string> State;

unordered_map<string, vector<Path>> connected;

void input(string& c1, string& c2) {
    connected.clear();

    int n, b;

    for (cin >> n >> b; b > 0; b--) {
        string w, d;
        int c;

        cin >> w >> d >> c;
        connected[w].push_back({d, c});
    }

    cin >> c1 >> c2;
}

int simulate(const string& from, const string& to) {
    int ret = INF;
    priority_queue<State> pq;
    unordered_map<string, int> dp;

    for (dp[from] = 0, pq.push({0, from}); !pq.empty(); pq.pop()) {
        int cur_cost = -pq.top().first;
        string cur_comb = pq.top().second;

        if (cur_comb == to) {
            ret = cur_cost;
            break;
        }

        const vector<Path>& adj = connected[cur_comb];

        for (int i = 0; i < adj.size(); i++) {
            string adj_comb = adj[i].first;
            int adj_cost = adj[i].second;

            if (dp.find(adj_comb) == dp.end() ||
                dp[adj_comb] > (cur_cost + adj_cost)) {
                dp[adj_comb] = (cur_cost + adj_cost);
                pq.push({-(cur_cost + adj_cost), adj_comb});
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        string c1, c2;
        int cov1, cov2;

        input(c1, c2);
        cov1 = simulate(c1, c2);
        cov2 = simulate(c2, c1);

        if (cov1 == cov2) {
            cout << "FIGHT!\n";
        } else {
            cout << ((cov1<cov2)?c1:c2) << '\n';
        }
    }

    return 0;
}