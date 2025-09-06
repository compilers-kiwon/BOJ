#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> connected;

void get_connection(void) {
    int n;

    for (cin >> n; n > 0; n--) {
        string name1, conn, name2;

        cin >> name1 >> conn >> name2;

        connected[name1].push_back(name2);
        connected[name2].push_back(name1);
    }
}

string simulate(const string& s1, const string& s2) {
    queue<string> q;
    unordered_map<string, bool> visited;

    for (q.push(s1), visited[s1] = true; !q.empty(); q.pop()) {
        string cur = q.front();

        if (cur == s2) {
            return "Related";
        }

        for (int i = 0; i < connected[cur].size(); i++) {
            const string& adj = connected[cur][i];

            if (visited[adj] == false) {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }

    return "Not Related";
}

void check_query(vector<string>& ans) {
    int m;

    for (cin >> m; m > 0; m--) {
        string name1, name2;
        cin >> name1 >> name2;
        ans.push_back(simulate(name1, name2));
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> ans;

    get_connection();
    check_query(ans);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}