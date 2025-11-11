#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, double> table = {
    {"N", 0.0f}, {"S", 180.0f}, {"E", 90.0f}, {"W", 270.0f},
    {"NE", 45.0f}, {"NW", 315.0f}, {"SE", 135.0f}, {"SW", 225.0f},
};

pair<int, int> get_dir(const string& cur) {
    const string s = "NESW";
    pair<int, int> ret;

    if (s.find(cur) != string::npos) {
        ret = {-1, 1};
    } else {
        ret = {1, -1};
    }

    return ret;
}

double solve(const string& str, int pos, pair<int, int> dir,
            const string& base, double cur_degree, double diff) {
    if (pos < 0) {
        return cur_degree;
    }

    double next_dir = (double)((str[pos]==base.front())?dir.first:dir.second);
    double next_degree = cur_degree + (diff * next_dir);

    return solve(str, pos - 1, dir, base, next_degree, diff / 2.0f);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cout << fixed; cout.precision(8);

    for (cin >> N; N > 0; N--) {
        string D;
        double degree;

        cin >> D;

        if (D.length() <= 2) {
            cout << table[D] << '\n';
        } else {
            string tail = D.substr(D.length() - 2, 2);
            pair<int, int> dir = get_dir(tail);
            int cur_pos = D.length() - 2 - 1;

            cout << solve(D, cur_pos, dir, tail, table[tail], 22.5f) << '\n';
        }
    }

    return 0;
}