#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

typedef long long int int64;
typedef pair<int64, int> State;
typedef pair<int, int64> Path;
typedef pair<int, int> Delivery;
typedef tuple<int, int, int64> Travel;

#define MAX_SIZE (10000+1)
#define MAX_NUM_OF_DELIVERIES (18)
#define INF (1000000LL*1000000LL*1000000LL)

int n, m, k;
vector<Path> connected[MAX_SIZE];
int64 cost_table[1<<MAX_NUM_OF_DELIVERIES][MAX_NUM_OF_DELIVERIES];
Delivery sched[MAX_NUM_OF_DELIVERIES];
map<Delivery, int64> mem_cost;

int64 find_shortest_path(int from, int to) {
    auto it = mem_cost.find({from, to});

    if (it != mem_cost.end()) {
        return it->second;
    }

    int64 ret = INF;
    priority_queue<State, vector<State>, greater<State>> pq;
    vector<int64> dp(n+1, INF);

    for (pq.push({0LL, from}), dp[from] = 0LL; !pq.empty(); pq.pop()) {
        int cur_cost = pq.top().first;
        int cur_city = pq.top().second;

        if (cur_city == to) {
            ret = cur_cost;
            break;
        }

        const vector<Path>& adj = connected[cur_city];

        for (int i = 0; i < adj.size(); ++i) {
            int adj_city = adj[i].first;
            int64 adj_cost = adj[i].second + cur_cost;

            if (adj_cost < dp[adj_city]) {
                pq.push({adj_cost, adj_city}), dp[adj_city] = adj_cost;
            }
        }
    }

    mem_cost[{from,to}] = mem_cost[{to,from}] = ret;
    return ret;
}

int64 simulate(void) {
    int64 ret = INF;
    queue<Travel> tq;
    int delivery_done = (1 << k) - 1;
    vector<int64> delivery_cost;

    for (int i = 0; i < k; ++i) {
        int deliver_from = sched[i].first;
        int deliver_to = sched[i].second;
        int64 c = find_shortest_path(deliver_from, deliver_to);

        if (c == INF) {
            return -1LL;
        }

        tq.push({1 << i, i, c});
        cost_table[1<<i][i] = c;
        delivery_cost.push_back(c);
    }

    for (; !tq.empty(); tq.pop()) {
        auto [done, cur, cost] = tq.front();

        if (done == delivery_done) {
            ret = min(ret, cost);
            continue;
        }

        for (int i = 0; i < k; ++i) {
            int d = 1 << i;

            if ((done & d) != 0) {
                continue;
            }

            int move_from = sched[cur].second;
            int move_to = sched[i].first;
            int64 move_cost = find_shortest_path(move_from, move_to);

            if (move_cost == INF) {
                continue;
            }

            int64 total_cost = cost + move_cost + delivery_cost[i];

            if (total_cost < cost_table[done+d][i]) {
                tq.push({done + d, i, total_cost});
                cost_table[done+d][i] = total_cost;
            }
        }
    }

    return (ret==INF)?-1LL:ret;
}

void input(void) {
    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        
        connected[u].push_back({v, (int64)l});
        connected[v].push_back({u, (int64)l});
    }

    for (int i = 0; i < k; ++i) {
        cin >> sched[i].first >> sched[i].second;
    }
}

void init(void) {
    for (int i = 0; i < (1 << k); ++i) {
        fill(&cost_table[i][0], &cost_table[i][k], INF);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init();
    cout << simulate() << '\n';

    return 0;
}