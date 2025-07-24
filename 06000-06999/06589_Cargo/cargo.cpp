#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<string, int> Road;
typedef pair<int, string> State;

bool input(unordered_map<string, vector<Road>>& connected,string& s, string &d) {
    int n, r;

    cin >> n >> r;

    if (n == 0 && r == 0) {
        return false;
    }

    for (int i = 1; i <= r; i++) {
        int limits;
        string c1, c2;

        cin >> c1 >> c2 >> limits;

        connected[c1].push_back({c2, limits});
        connected[c2].push_back({c1, limits});
    }

    cin >> s >> d;

    return true;
}

int simulate(unordered_map<string, vector<Road>>& connected,string& s, string &d) {
    const int INF = 0x7FFFFFFF;

    priority_queue<State> pq;
    unordered_map<string, int> dp;

    pq.push({INF, s});
    dp[s] = INF;

    for (; !pq.empty();) {
        int cur_limits = pq.top().first;
        string cur_city = pq.top().second;

        pq.pop();

        if (cur_city == d) {
            continue;
        }

        const vector<Road>& adj = connected[cur_city];

        for (int i = 0; i <adj.size(); i++) {
            const string& adj_city = adj[i].first;
            const int& adj_limits = adj[i].second;

            if (dp.find(adj_city) == dp.end() ||
                    min(cur_limits, adj_limits) > dp[adj_city]) {
                dp[adj_city] = min(cur_limits, adj_limits);
                pq.push({min(cur_limits, adj_limits), adj_city});
            }
        }
    }

    return dp[d];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int n = 1;; n++) {
        string start, destination;
        unordered_map<string, vector<Road>> connected;

        if (input(connected, start, destination) == false) {
            break;
        }

        cout << "Scenario #" << n <<'\n';
        cout << simulate(connected, start, destination) << " tons\n\n";
    }

    return 0;
}