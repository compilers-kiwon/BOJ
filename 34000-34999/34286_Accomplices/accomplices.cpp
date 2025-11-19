#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (20+1)

int n, m, cnt[MAX_SIZE];
bool friendship[MAX_SIZE][MAX_SIZE];

bool check_friends(const vector<int>& selected) {
    for (int i = 0; i < selected.size(); i++) {
        for (int j = i + 1; j < selected.size(); j++) {
            if (friendship[selected[i]][selected[j]] == true) {
                return true;
            }
        }
    }

    return false;
}

void dfs(int cur, vector<int>& selected) {
    if (cur > n) {
        if (check_friends(selected) == false) {
            cnt[selected.size()]++;
        }

        return;
    }

    selected.push_back(cur);
    dfs(cur + 1, selected);
    selected.pop_back();

    dfs(cur + 1, selected);
}

void input(void) {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        friendship[a][b] = friendship[b][a] = true;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> g;

    input();
    dfs(1, g);

    for (int i = 0; i <= n; i++) {
        cout << cnt[i] << ((i==n)?'\n':' ');
    }

    return 0;
}