#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (200000+1)

int N, M, Q, cnt[MAX_SIZE];
bool built[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void input(void) {
    cin >> N >> M >> Q;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        connected[u].push_back(v), connected[v].push_back(u);
    }
}

void update_state(int built_village) {
    if (built[built_village] == true) {
        return;
    }

    const vector<int>& adj = connected[built_village];

    for (int i = 0; i < adj.size(); i++) {
        cnt[adj[i]]++;
    }

    built[built_village] = true;
}

void do_query(void) {
    for (; Q > 0; Q--) {
        int q, i;

        cin >> q >> i;

        if (q == 1) {
            update_state(i);
        } else {
            cout << cnt[i] << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    do_query();

    return 0;
}