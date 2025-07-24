#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)
#define ROOT (1)

typedef pair<int, pair<int, int>> Connection;

int N, M, parent[MAX_SIZE];
priority_queue<Connection> pq;

int find_parent(int cur) {
    int& ret = parent[cur];

    if (ret != cur) {
        ret = find_parent(ret);
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push({C, {A, B}});
    }
}

int simulate(void) {
    int ret = 0;

    for (; !pq.empty(); pq.pop()) {
        int c, b1, b2, p1, p2;

        c = pq.top().first;
        b1 = pq.top().second.first;
        b2 = pq.top().second.second;

        p1 = find_parent(b1);
        p2 = find_parent(b2);

        if (p1 == p2) {
            continue;
        }

        ret += c;
        parent[max(p1, p2)] = min(p1, p2);
    }

    for (int i = 1; i <= N; i++) {
        if (find_parent(i) != ROOT) {
            ret = -1;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}