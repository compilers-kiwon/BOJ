#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF (0x7FFFFFFF)
#define NUM_OF_TEAMS (4)

void input(vector<int> h[]) {
    int N;

    cin >> N;

    for (int t = 0; t < NUM_OF_TEAMS; t++) {
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            h[t].push_back(n);
        }

        sort(h[t].begin(), h[t].end());
    }
}

int get_min_max_diff(const vector<int>& selected) {
    int min_height = INF;
    int max_height = 0;

    for (int i = 0; i < selected.size(); i++) {
        min_height = min(min_height, selected[i]);
        max_height = max(max_height, selected[i]);
    }

    return max_height - min_height;
}

void dfs(int cur_team, vector<int> h[],
            vector<int>& selected, int& min_diff) {
    if (cur_team == NUM_OF_TEAMS) {
        min_diff = min(min_diff, get_min_max_diff(selected));
        return;
    }

    vector<int>& cur = h[cur_team];
    auto lower = lower_bound(cur.begin(), cur.end(), selected.front());
    
    if (*lower == selected.front() || lower == cur.begin() || lower == cur.end()) {
        if (lower == cur.end()) {
            lower--;
        }

        selected.push_back(*lower);
        dfs(cur_team + 1, h, selected, min_diff);
        selected.pop_back();
    } else {
        int lo = *(lower - 1);
        int hi = *lower;
    
        selected.push_back(lo);
        dfs(cur_team + 1, h, selected, min_diff);
        selected.pop_back();

        selected.push_back(hi);
        dfs(cur_team + 1, h, selected, min_diff);
        selected.pop_back();
    }
}

int simulate(vector<int> h[]) {
    int ret = INF;

    for (auto it = h[0].begin(); it != h[0].end(); it++) {
        vector<int> selected = {*it};
        dfs(1, h, selected, ret);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> height[NUM_OF_TEAMS];

    input(height);
    cout << simulate(height) << '\n';

    return 0;
}