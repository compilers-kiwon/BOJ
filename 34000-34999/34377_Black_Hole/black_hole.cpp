#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dp;
unordered_map<string, vector<string>> connected;

#define NONE (0)

string input(void) {
    int N;
    string ret;

    for (cin >> N >> ret; N > 0; N--) {
        string src,dst;
        cin >> src >> dst;
        connected[src].push_back(dst);
    }

    return ret;
}

int simulate(const string& start) {
    int ret = NONE;
    queue<string> q;

    for (q.push(start); !q.empty(); q.pop()) {
        int cur_steps;
        string cur_article = q.front();

        if (dp.find(cur_article) == dp.end()) {
            cur_steps = 0;
        } else {
            if (cur_article == start) {
                ret = dp[cur_article];
                break;
            } else {
                cur_steps = dp[cur_article];
            }
        }
        
        const vector<string>& adj = connected[cur_article];

        for (int i = 0; i < adj.size(); i++) {
            const string& adj_article = adj[i];

            if (dp.find(adj_article) == dp.end()) {
                dp[adj_article] = cur_steps + 1;
                q.push(adj_article);
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s = input();
    int cycle = simulate(s);

    if (cycle == NONE) {
        cout << "NO BLACK HOLE\n";
    } else {
        cout << cycle << '\n';
    }

    return 0;
}