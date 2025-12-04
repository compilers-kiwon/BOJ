#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (30000+1)
#define MAX_CRY (3000+1)

int N, M, K, c[MAX_SIZE], dp[MAX_SIZE][MAX_CRY];
int num_of_groups, num_of_group_candy[MAX_SIZE], size_of_group[MAX_SIZE];
vector<int> connected[MAX_SIZE];
bool visited[MAX_SIZE];

void input(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        connected[a].push_back(b), connected[b].push_back(a);
    }
}

void dfs(int cur, vector<int>& g) {
    const vector<int>& adj = connected[cur];

    for (int i = 0; i < adj.size(); i++) {
        if (visited[adj[i]] == false) {
            visited[adj[i]] = true;
            g.push_back(adj[i]);
            dfs(adj[i], g);
        }
    }
}

int get_sum_of_candy(const vector<int>& g) {
    int ret = 0;

    for (int i = 0; i < g.size(); i++) {
        ret += c[g[i]];
    }

    return ret;
}

void find_group(void) {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == true) {
            continue;
        }

        vector<int> g;

        visited[i] = true, g.push_back(i);
        dfs(i, g);

        ++num_of_groups;
        size_of_group[num_of_groups] = g.size();
        num_of_group_candy[num_of_groups] = get_sum_of_candy(g);
    }
}

int simulate(void) {
    for (int cur_group = 1; cur_group <= num_of_groups; cur_group++) {
        int cur_size = size_of_group[cur_group];
        int cur_candy = num_of_group_candy[cur_group];

        if (cur_size < K) {
            dp[cur_group][cur_size] = cur_candy;
        }

        for (int prev_size = 1; prev_size < K; prev_size++) {
            int prev_group = cur_group - 1;

            if (dp[prev_group][prev_size] == 0) {
                continue;
            }

            dp[cur_group][prev_size] =
                max(dp[cur_group][prev_size], dp[prev_group][prev_size]);
            
            if ((prev_size + cur_size) < K) {
                dp[cur_group][prev_size+cur_size] = 
                    max(dp[cur_group][prev_size+cur_size], dp[prev_group][prev_size] + cur_candy);
            }
        }
    }

    int ret = 0;

    for (int i = 1; i <= K; i++) {
        ret = max(ret, dp[num_of_groups][i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    find_group();
    cout << simulate() << '\n';

    return 0;
}