#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> Pos;
typedef unordered_map<int64, vector<int64>> Parallel;

void input(vector<Pos>& p, Parallel& to_y, Parallel& to_x) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int64 X, Y;

        cin >> X >> Y;
        p.push_back({X, Y});

        to_x[Y].push_back(X);
        to_y[X].push_back(Y);
    }
}

int64 simulate(vector<Pos>& p, Parallel& to_y, Parallel& to_x) {
    int64 ret = 0LL;

    for (int i = 0; i < p.size(); ++i) {
        int64 x = p[i].first;
        int64 y = p[i].second;

        vector<int64>& parallel_to_y = to_y[x];
        vector<int64>& parallel_to_x = to_x[y];
        
        for (int j = 0; j < parallel_to_y.size(); ++j) {
            for (int k = 0; k < parallel_to_x.size(); ++k) {
                int64 dy = abs(y - parallel_to_y[j]);
                int64 dx = abs(x - parallel_to_x[k]);
                ret = max(ret, dy * dx);
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> p;
    Parallel to_y, to_x;

    input(p, to_y, to_x);
    cout << simulate(p, to_y, to_x) << '\n';

    return 0;
}