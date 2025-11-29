#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

enum {
    GRAPH = 0,
    NODE = 1,
};

void simulate(const vector<string>& nodes, 
        unordered_map<string, vector<string>>& connected) {
    for (int i = 0; i < nodes.size(); i++) {
        queue<string> q;
        vector<string> ans;
        unordered_set<string> visited;

        q.push(nodes[i]), visited.insert(nodes[i]);

        for (int step = 1; step <= 2; step++) {
            for (int i = 1, size = q.size(); i <= size; i++, q.pop()) {
                string cur = q.front();

                for (auto it = connected[cur].begin(); it < connected[cur].end(); it++) {
                    if (visited.find(*it) == visited.end()) {
                        visited.insert(*it);

                        if (step == 2) {
                            ans.push_back(*it);
                        } else {
                            q.push(*it);
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());

        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j] << ((j==ans.size()-1)?'\n':' ');
        }
    }
}

void remove_spaces(string& str) {
    for (; !str.empty() && str.back() == ' '; str.pop_back());
}

void parse(const string& str, vector<string>& result) {
    string cur;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (cur.empty()) {
                continue;
            }

            result.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

void build_graph(string& str, unordered_map<string, vector<string>>& connected) {
    vector<string> n;

    str.push_back(' ');
    parse(str, n);

    for (int i = 1; i < n.size(); i++) {
        connected[n.front()].push_back(n[i]);
        connected[n[i]].push_back(n.front());
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> inputs;

    for (string s; getline(cin, s);) {
        inputs.push_back(s);
    }

    inputs.push_back("GRAPH BEGIN");

    int state;
    vector<string> nodes;
    unordered_map<string, vector<string>> connected;

    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] == "GRAPH BEGIN") {
            simulate(nodes, connected);
            nodes.clear(), connected.clear();
            
            state = GRAPH;
            continue;
        }

        if (inputs[i] == "GRAPH END") {
            state = NODE;
            continue;
        }

        switch (state) {
            case GRAPH: build_graph(inputs[i], connected); break;
            case NODE:
                remove_spaces(inputs[i]);
                nodes.push_back(inputs[i]);
                break;
            default:
                // do nothing
                break;
        }
    }

    return 0;
}