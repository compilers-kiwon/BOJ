#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int int64;
typedef pair<int, int64> Path;

#define MAX_SIZE (100000+1)
#define INF (1000000LL*1000000LL)

int N, M, S, T;
bool is_queued[MAX_SIZE];
int64 a[MAX_SIZE], dp_time[MAX_SIZE], dp_water[MAX_SIZE];
vector<Path> connected[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a[i], dp_time[i] = dp_water[i] = INF;
    }

    cin >> M;

    for (int i = 1; i <= M; i++) {
        int u, v, w;
        
        cin >> u >> v >> w;

        connected[u].push_back({v, w});
        connected[v].push_back({u, w});
    }

    cin >> S >> T;
}

bool simulate(void) {
    queue<int> q;

    q.push(S), is_queued[S] = true;
    dp_time[S] = 0LL, dp_water[S] = a[S];

    for (; !q.empty();) {
        int cur_pos = q.front();
        int64 cur_time = dp_time[cur_pos];
        int64 cur_water = dp_water[cur_pos];

        q.pop(), is_queued[cur_pos] = false;

        if (cur_pos == T) {
            continue;
        }

        const vector<Path>& adj = connected[cur_pos];

        for (int i = 0; i < adj.size(); i++) {
            int adj_pos = adj[i].first;
            int64 adj_time = cur_time + adj[i].second;
            int64 adj_water = cur_water + a[adj_pos];

            if (adj_time < dp_time[adj_pos] ||
                (adj_time == dp_time[adj_pos] && adj_water > dp_water[adj_pos])) {
                if (is_queued[adj_pos] == false) {
                    q.push(adj_pos), is_queued[adj_pos] = true;
                }

                dp_time[adj_pos] = adj_time, dp_water[adj_pos] = adj_water;
            }
        }
    }

    return (dp_time[T] != INF);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    
    if (simulate()) {
        cout << dp_time[T] << ' ' << dp_water[T] << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}