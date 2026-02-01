#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (5000+1)

int P, NS, T;
vector<int> connected[MAX_SIZE];

bool dfs(int cur, vector<int>& path) {
    path.push_back(cur);
    
    if (cur == T) {
        return true;
    }

    for (int i = 0; i < connected[cur].size(); ++i) {
        int adj = connected[cur][i];

        if (dfs(adj, path) == true) {
            return true;
        }
    }

    path.pop_back();

    return false;
}

void input(void) {
    cin >> P >> NS >> T;

    for (int i = 1; i <= NS; ++i) {
        int N, B1, B2;
        cin >> N >> B1 >> B2;
        connected[N] = {B1, B2};
    }
}

void print(const vector<int>& p) {
    cout << p.size() << '\n';

    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> path;

    input();
    dfs(1, path);
    print(path);

    return 0;
}