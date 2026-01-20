#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

#define TBD (-1)
#define NONE (0)
#define MAX_SIZE (10000+1)

int N, M, num_of_scc, my_scc[MAX_SIZE], dp[MAX_SIZE];
bool visited[MAX_SIZE];
vector<int> f_connected[MAX_SIZE], b_connected[MAX_SIZE];
vector<int> scc[MAX_SIZE];
unordered_set<int> connected_scc[MAX_SIZE];
stack<int> st;

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int A, B;
        cin >> A >> B;
        f_connected[A].push_back(B), b_connected[B].push_back(A);
    }
}

void dfs(int cur, int scc_ptr, vector<int> adj[]) {
    visited[cur] = true;

    if (scc_ptr != NONE) {
        scc[scc_ptr].push_back(cur);
    }

    for (int i = 0; i < adj[cur].size(); i++) {
        if (visited[adj[cur][i]] == false) {
            dfs(adj[cur][i], scc_ptr, adj);
        }
    }

    st.push(cur);
}

void get_scc(void) {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            dfs(i, NONE, f_connected);
        }
    }

    fill(&visited[1], &visited[N+1], false);

    for (; !st.empty();) {
        int cur = st.top();

        st.pop();

        if (visited[cur] == true) {
            continue;
        }

        dfs(cur, ++num_of_scc, b_connected);
    }

    for (int i = 1; i <= num_of_scc; i++) {
        const vector<int>& cur_scc = scc[i];

        for (int j = 0; j < cur_scc.size(); j++) {
            my_scc[cur_scc[j]] = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        const vector<int>& adj = b_connected[i];

        for (int j = 0; j < adj.size(); j++) {
            int to_scc = my_scc[i];
            int from_scc = my_scc[adj[j]];

            if (from_scc != to_scc) {
                connected_scc[to_scc].insert(from_scc);
            }
        }
    }
}

int get_dp(int cur_scc) {
    int& ret = dp[cur_scc];

    if (ret != TBD) {
        return ret;
    }

    ret = scc[cur_scc].size();

    for (auto it = connected_scc[cur_scc].begin();
            it != connected_scc[cur_scc].end(); it++) {
        ret += get_dp(*it);
    }

    return ret;
}

int solve(void) {
    int ret = 0;

    for (int i = 1; i <= num_of_scc; i++) {
        if (dp[i] == N) {
            ret = scc[i].size();
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_scc();

    fill(&dp[1], &dp[num_of_scc+1], TBD);

    for (int i = 1; i <= num_of_scc; i++) {
        get_dp(i);
    }

    cout << solve() << '\n';

    return 0;
}