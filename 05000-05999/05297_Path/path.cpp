#include <iostream>
#include <vector>

using namespace std;

#define TBD (-1)
#define INF (0x7FFFFFFF)

typedef pair<int, int> Path;

int n, b, s, e;
vector<int> dp;
vector<vector<Path>> connected;

void input(void) {
    cin >> n >> b >> s >> e;

    dp = vector<int>(n, TBD);
    connected = vector<vector<Path>>(n);

    for (int i = 1; i <= b; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;

        connected[a].push_back({b, c});
        connected[b].push_back({a, c});
    }

    dp[s] = 0;
}

int get_dp(int pos) {
    int& ret = dp[pos];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;

    const vector<Path>& adj = connected[pos];

    for (int i = 0; i < adj.size(); i++) {
        int adj_pos = adj[i].first;
        int adj_native = adj[i].second;
        int prev_native = get_dp(adj_pos);

        if (prev_native != INF) {
            ret = min(ret, prev_native + adj_native);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_natives;

    input();
    num_of_natives = get_dp(e);

    if (num_of_natives == INF) {
        cout << "It's over with Captain Jack. At least till Pirates of the Caribbean 3.\n";
    } else {
        cout << num_of_natives << " native(s) on the easiest way for Captain Jack.\n";
    }

    return 0;
}