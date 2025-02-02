#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM_OF_CITIES (100000+1)

enum {
    INSTALLED = 0,
    REMOVED = 1,
    MAX_STATE = 2
};

bool visited[MAX_NUM_OF_CITIES];
int dp[MAX_NUM_OF_CITIES][MAX_STATE];
vector<int> connected[MAX_NUM_OF_CITIES];

void input(void) {
    int N;

    cin>>N;

    for (int i = 1; i < N; i++) {
        int u, v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }
}

void get_dp(int cur_city) {
    visited[cur_city] = true;
    dp[cur_city][INSTALLED] = 1;

    for (int i = 0; i < connected[cur_city].size(); i++) {
        const int& adj_city = connected[cur_city][i];

        if (visited[adj_city] == true) {
            continue;
        }

        get_dp(adj_city);

        dp[cur_city][REMOVED] +=  dp[adj_city][INSTALLED];
        dp[cur_city][INSTALLED] +=
            min(dp[adj_city][INSTALLED], dp[adj_city][REMOVED]);
    } 
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_dp(1);
    cout<<min(dp[1][INSTALLED], dp[1][REMOVED])<<'\n';

    return 0;
}