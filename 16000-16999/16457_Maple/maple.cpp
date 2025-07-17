#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> required_skills;

bool possible_to_clear(const vector<int>& required, bool available[]) {
    for (int i = 0; i < required.size(); i++) {
        if (available[required[i]] == false) {
            return false;
        }
    }

    return true;
}

int simulate(bool selected[]) {
    int ret = 0;

    for (int i = 0; i < required_skills.size(); i++) {
        if (possible_to_clear(required_skills[i], selected) == true) {
            ret++;
        }    
    }

    return ret;
}

void dfs(int cur_skill, bool selected[], int num_of_keys,
            int num_of_selected_skills, int& max_num_of_clears) {
    if (num_of_selected_skills == num_of_keys) {
        max_num_of_clears = max(max_num_of_clears, simulate(selected));
        return;
    }

    if (cur_skill > (2 * num_of_keys)) {
        return;
    }

    selected[cur_skill] = true;
    dfs(cur_skill + 1, selected, num_of_keys, num_of_selected_skills + 1, max_num_of_clears);
    selected[cur_skill] = false;

    dfs(cur_skill + 1, selected, num_of_keys, num_of_selected_skills, max_num_of_clears);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m, k, ans;
    bool my_skills[20+1] = {false, };

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        vector<int> r;

        for (int j = 1; j <= k; j++) {
            int s;
            cin >> s;
            r.push_back(s);
        }

        required_skills.push_back(r);
    }

    ans = 0;
    dfs(1, my_skills, n, 0, ans);
    cout << ans << '\n';

    return 0;
}