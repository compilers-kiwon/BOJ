#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define NONE (-1)
#define MAX_SIZE (2000)

int V, E, Q, num_of_scc, my_scc[MAX_SIZE];
bool visited[MAX_SIZE];
set<int> scc_connected[MAX_SIZE];
vector<int> f_connected[MAX_SIZE], b_connected[MAX_SIZE], scc[MAX_SIZE];
stack<int> st;

void read_graph(void) {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int A, B;

        cin >> A >> B;
        
        f_connected[A].push_back(B);
        b_connected[B].push_back(A);
    }
}

void dfs(int v, vector<int> connected[], int scc_num) {
    visited[v] = true;

    if (scc_num != NONE) {
        scc[scc_num].push_back(v);
    }

    for (int i = 0; i < connected[v].size(); i++) {
        int adj = connected[v][i];

        if (visited[adj] == false) {
            dfs(adj, connected, scc_num);
        }
    }

    if (scc_num == NONE) {
        st.push(v);
    }
}

void build_scc(void) {
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            dfs(i, f_connected, NONE);
        }
    }

    fill(visited, visited + V, false);

    for (; !st.empty(); st.pop()) {
        int cur = st.top();

        if (visited[cur] == true) {
            continue;
        }

        dfs(cur, b_connected, ++num_of_scc);
    }

    for (int i = 1; i <= num_of_scc; i++) {
        const vector<int>& cur = scc[i];

        for (int j = 0; j < cur.size(); j++) {
            my_scc[cur[j]] = i;
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < f_connected[i].size(); j++) {
            int from = my_scc[i];
            int to = my_scc[f_connected[i][j]];
            scc_connected[from].insert(to);
        }
    }
}

int scc_dfs(int cur, int end) {
    visited[cur] = true;

    if (cur == end) {
        return 1;
    }

    for (auto it = scc_connected[cur].begin(); it != scc_connected[cur].end(); ++it) {
        if (visited[*it] == false && scc_dfs(*it, end) == 1) {
            return 1;
        }
    }

    return 0;
}

int do_query(int X, int Y) {
    if (my_scc[X] == my_scc[Y]) {
        return 1;
    }

    fill(visited, visited + num_of_scc + 1, false);

    return scc_dfs(my_scc[X], my_scc[Y]);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_graph();
    build_scc();

    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int X, Y;
        cin >> X >> Y;
        cout << do_query(X, Y) << '\n';
    }

    return 0;
}