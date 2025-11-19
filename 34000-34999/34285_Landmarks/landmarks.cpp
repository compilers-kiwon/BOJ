#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> Pos;

unordered_map<string, Pos> landmarks;

int64 get_dist(const string& s, const string& d) {
    Pos l1 = landmarks[s];
    Pos l2 = landmarks[d];
    return (abs(l1.first - l2.first) + abs(l1.second - l2.second));
}

void input(vector<string>& p) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        int64 x, y;

        cin >> s >> x >> y;
        landmarks[s] = {x, y};
    }

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        p.push_back(s);
    }
}

int64 simulate(const vector<string>& p) {
    int64 ret = 0;

    for (int i = 0; i < p.size() - 1; i++) {
        ret += get_dist(p[i], p[i+1]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> path;
    input(path);
    cout << simulate(path) << '\n';

    return 0;
}