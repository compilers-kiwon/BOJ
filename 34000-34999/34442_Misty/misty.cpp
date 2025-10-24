#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define MAX_SIZE (100+1)

typedef tuple<int, int, int, int> Trail;

int n, m, p[MAX_SIZE];
priority_queue<Trail> pq;

int find_parent(int n) {
    int& ret = p[n];

    if (ret != n) {
        ret = find_parent(ret);
    }

    return ret;
}

void input(void) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int h1, h2, d;
        cin >> h1 >> h2 >> d;
        pq.push({-d, i, h1, h2});
    }
}

void simulate(vector<int>& used) {
    for (; !pq.empty(); pq.pop()) {
        auto [d, label, h1, h2] = pq.top();

        int h1_p = find_parent(h1);
        int h2_p = find_parent(h2);

        if (h1_p == h2_p) {
            continue;
        }

        p[max(h1_p, h2_p)] = min(h1_p, h2_p);
        used.push_back(label);
    }
}

void print(const vector<int>& used) {
    cout << used.size() << '\n';

    for (int i = 0; i < used.size(); i++) {
        cout << used[i] << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> used;

    input();
    simulate(used);
    print(used);

    return 0;
}