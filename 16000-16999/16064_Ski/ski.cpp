#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (1000+1)
#define TBD (-1)

typedef pair<int, int> Path;

int n, m, dp[MAX_SIZE];
vector<Path> connected[MAX_SIZE];

void input(void) {
    cin >> n >> m;
    fill(&dp[1], &dp[n+1], TBD);

    for (int i = 1; i <= m; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        connected[t].push_back({s, c});
    }
}

int get_dp(int p) {
    int& ret = dp[p];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    for (int i = 0; i <connected[p].size(); i++) {
        int prev = connected[p][i].first;
        int condition = connected[p][i].second;

        ret = max(ret, get_dp(prev) + condition);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_condition = 0;

    input();

    for (int i = 1; i <= n; i++) {
        max_condition = max(max_condition, get_dp(i));
    }

    cout << max_condition << '\n';

    return 0;
}