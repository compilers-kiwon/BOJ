#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE (100)

int input(vector<int> connected[]) {
    int n, k;

    for (cin >> n >> k; k > 0; k--) {
        int a, b;

        cin >> a >> b;
        
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    return n;
}

bool simulate(int num_of_sites, vector<int> connected[]) {
    int cnt;
    queue<int> q;
    vector<bool> visited(num_of_sites, false);

    for (q.push(0), visited[0] = true, cnt = 1; !q.empty(); q.pop()) {
        int cur = q.front();

        for (int i = 0; i < connected[cur].size(); i++) {
            int adj = connected[cur][i];

            if (visited[adj] == false) {
                q.push(adj), visited[adj] = true, ++cnt;
            }
        }
    }

    return (num_of_sites == cnt);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int num_of_sites;
        vector<int> connected[MAX_SIZE];

        num_of_sites = input(connected);
        cout << (simulate(num_of_sites, connected)?
                    "Connected":"Not connected") << ".\n";
    }

    return 0;
}