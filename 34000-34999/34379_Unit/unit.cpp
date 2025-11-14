#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef pair<string, double> State;

unordered_set<string> visited;
unordered_map<string, unordered_map<string, double>> conversion_table;

double convert_unit(const string& start, const string& end) {
    queue<State> q;
    double ret = 0.0f;

    for (q.push({start, 1.0f}), visited.insert(start); !q.empty(); q.pop()) {
        string cur_unit = q.front().first;
        double cur_ratio = q.front().second;

        if (cur_unit == end) {
            ret = cur_ratio;
            break;
        }

        const unordered_map<string, double>& adj = conversion_table[cur_unit];

        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (visited.find(it->first) != visited.end()) {
                continue;
            }

            visited.insert(it->first);
            q.push({it->first, cur_ratio * it->second});
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string u1, u2;
    double m, d, a, r;

    for (cin >> n; n > 0; n--) {
        cin >> u1 >> u2 >> m >> d;

        conversion_table[u1][u2] = m / d;
        conversion_table[u2][u1] = d / m;
    }

    cin >> a >> u1 >> u2;
    r = convert_unit(u1, u2);

    if (r == 0.0f) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << fixed; cout.precision(2);
        cout << a * r << '\n';
    }

    return 0;
}