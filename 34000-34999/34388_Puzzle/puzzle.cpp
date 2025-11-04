#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

const string solved = "123-";
const int PUZZLE_SIZE = 4;

const vector<vector<int>> adj = {
    {1, 2}, {0, 3}, {0, 3}, {1, 2}
};

unordered_map<string, int> visited;

typedef pair<string, int> State;

int simulate(const string& s) {
    int ret;
    queue<State> q;

    for (q.push({s, 0}), visited[s] = true; !q.empty(); q.pop()) {
        State cur = q.front();

        if (cur.first == solved) {
            ret = cur.second;
            break;
        }

        int empty_pos = cur.first.find('-');

        for (int i = 0; i < adj[empty_pos].size(); i++) {
            int swap_pos = adj[empty_pos][i];
            State next;

            next.first = cur.first;
            swap(next.first[empty_pos], next.first[swap_pos]);

            if (visited[next.first] == false) {
                next.second = cur.second + 1;
                visited[next.first] = true;
                q.push(next);
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string init_state;

    for (int i = 0; i < PUZZLE_SIZE; i++) {
        char c;
        cin >> c;
        init_state.push_back(c);
    }

    cout << simulate(init_state) << '\n';
    return 0;
}