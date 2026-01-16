#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE (2000+1)

typedef long long int int64;
typedef pair<int64, int64> Pos;

int n;
bool visited[MAX_SIZE];
Pos p[MAX_SIZE];
int64 d;
vector<int> connected[MAX_SIZE];
map<int, vector<int>> graph;

void input(void) {

    cin >> n >> d;
    d *= d;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
}

void get_connected_island(void) {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int64 dx = p[i].first - p[j].first;
            int64 dy = p[i].second - p[j].second;
            int64 cur_d = dx * dx + dy * dy;

            if (cur_d <= d) {
                connected[i].push_back(j);
                connected[j].push_back(i);
            }
        }
    }
}

void dfs(int n, vector<int>& v) {
    visited[n] = true, v.push_back(n);

    for (int i = 0; i < connected[n].size(); i++) {
        int adj = connected[n][i];

        if (visited[adj] == false) {
            dfs(adj, v);
        }
    }
}

void simulate(void) {
    for (int i = 1; i <= n ; i++) {
        if (visited[i] == false) {
            vector<int> g;
            
            dfs(i, g);
            
            for (int j = 0; j < g.size(); j++) {
                graph[g.size()].push_back(g[j]);
            }
        }
    }
}

void print(void) {
    vector<int> sorted;

    for (auto it = graph.rbegin(); it != graph.rend(); it++) {
        vector<int>& g = it->second;

        sort(g.begin(), g.end());

        for (int i = 0; i < g.size(); i++) {
            sorted.push_back(g[i]);
        }
    }

    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << ((i==sorted.size()-1)?'\n':' ');
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected_island();
    simulate();
    print();

    return 0;
}