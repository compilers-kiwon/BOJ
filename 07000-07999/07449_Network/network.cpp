#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE (100000)
#define INF (0x7FFFFFFF)

int visited[MAX_SIZE], N, c1, c2;
vector<int> connected[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int c, nc;

        cin >> c >> nc;
        visited[c] = INF;

        for (int j = 0; j < nc; ++j) {
            int other;
            cin >> other;
            connected[c].push_back(other);
        }
    }

    cin >> c1 >> c2;
}

int simulate(void) {
    int ret;
    queue<int> q;

    for (q.push(c1), visited[c1] = 0; !q.empty(); q.pop()) {
        int cur = q.front();

        if (cur == c2) {
            ret = visited[c2];
            break;
        }

        for (int i = 0; i < connected[cur].size(); ++i) {
            int adj = connected[cur][i];

            if (visited[adj] != INF) {
                continue;
            }

            q.push(adj);
            visited[adj] = visited[cur] + 1;
        }
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << c1 << ' ' << c2 << ' '
            << simulate() - 1 << '\n';
    
    return 0;
}