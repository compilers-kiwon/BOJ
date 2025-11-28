#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

typedef string Node;
typedef string Edge;

void parse(const string& s, vector<string>& result) {
    string cur;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (!cur.empty()) {
                result.push_back(cur);
                cur.clear();
            }
        } else {
            cur.push_back(s[i]);
        }
    }
}

void input(vector<vector<string>>& g) {
    for (string s;;) {
        getline(cin, s);

        if (s == "GRAPH END") {
            break;
        }

        vector<string> cur;

        s.push_back(' ');
        parse(s, cur);
        g.push_back(cur);
    }
}

void analyze_graph(const vector<vector<string>>& g,
                    unordered_set<Node>& n, unordered_set<Edge>& e) {
    for (int i = 0; i < g.size(); i++) {
        const string& a = g[i][0];

        n.insert(a);

        for (int j = 1; j < g[i].size(); j++) {
            const string& b = g[i][j];
            
            n.insert(b);
            e.insert(min(a, b) + " " + max(a, b));
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string s;

        getline(cin, s);

        if (s != "GRAPH BEGIN") {
            break;
        }

        vector<vector<string>> graph;
        unordered_set<Node> nodes;
        unordered_set<Edge> edges;

        input(graph);
        analyze_graph(graph, nodes, edges);

        cout << "NODES " << nodes.size() <<
                " EDGES " << edges.size() << '\n';
    }

    return 0;
}