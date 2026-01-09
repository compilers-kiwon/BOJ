#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define NUM_OF_HOPS (2)
#define MAX_SIZE (100+1)

int input(vector<int> c[]) {
    int n, e;

    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        string v1, v2;
        int num1, num2;

        cin >> v1 >> v2;
        num1 = stoi(v1.substr(1)), num2 = stoi(v2.substr(1));
        c[num1].push_back(num2), c[num2].push_back(num1);
    }

    string vi;
    cin >> vi;
    return stoi(vi.substr(1));
}

int simulate(int v, vector<int> c[]) {
    int ret;
    queue<int> q;
    bool visited[MAX_SIZE];

    fill(&visited[1], &visited[MAX_SIZE], false);
    q.push(v), visited[v] = true, ret = 0;

    for (int h = 1; h <= NUM_OF_HOPS; h++) {
        for (int i = 1, size = q.size(); i <= size; i++, q.pop()) {
            const vector<int>& adj = c[q.front()];

            for (int j = 0; j < adj.size(); j++) {
                int a = adj[j];

                if (visited[a] == true) {
                    continue;
                }

                q.push(a), visited[a] = true, ret++;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int sv;
        vector<int> connected[MAX_SIZE];

        sv = input(connected);
        cout << "The number of supervillains in 2-hop neighborhood of v"
                << sv << " is " << simulate(sv, connected) << '\n';
    }

    return 0;
}