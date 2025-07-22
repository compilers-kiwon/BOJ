#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (1000+1)
#define ROOT (1)

typedef pair<int, int> Query; // <p1, p2>

int N, Q, parent[MAX_SIZE], depth[MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

vector<int> connected[MAX_SIZE];
vector<Query> q;

void input(void) {
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        int A, B, L;

        cin >> A >> B >> L;
        dist[A][B] = dist[B][A] = L;

        connected[A].push_back(B);
        connected[B].push_back(A);
    }

    for (int i = 1; i <= Q; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        q.push_back({p1, p2});
    }
}

void analyze(int cur, int p, int d) {
    parent[cur] = p;
    depth[cur] = d;

    vector<int>& adj = connected[cur];

    for (int i = 0; i < adj.size(); i++) {
        if (adj[i] != p) {
            analyze(adj[i], cur, d + 1);
        }    
    }
}

int get(int p1, int p2) {
    int ret = 0;
    int near, far;

    if (depth[p1] < depth[p2]) {
        near = p1;
        far = p2;
    } else {
        near = p2;
        far = p1;
    }

    for (; depth[far] != depth[near]; far = parent[far]) {
        ret += dist[far][parent[far]];
    }

    for (; far != near; far = parent[far], near = parent[near]) {
        ret += dist[far][parent[far]];
        ret += dist[near][parent[near]];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    analyze(ROOT, 0, 0);

    for (int i = 0; i < q.size(); i++) {
        cout << get(q[i].first, q[i].second) << '\n';
    }

    return 0;
}