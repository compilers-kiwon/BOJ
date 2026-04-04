#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, closest;
    vector<pair<int64, int64>> p;
    int64 min_dist = 1000000LL * 1000000LL * 1000000LL;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int64 x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    for (int i = 1; i < p.size(); ++i) {
        int64 dx = p.front().first - p[i].first;
        int64 dy = p.front().second - p[i].second;
        int64 cur_dist = (dx * dx) + (dy * dy);

        if (cur_dist < min_dist) {
            closest = i;
            min_dist = cur_dist;
        }
    }

    cout << p.front().first << ' ' << p.front().second << '\n';
    cout << p[closest].first << ' ' << p[closest].second << '\n';
    cout << fixed; cout.precision(2); cout << sqrt(min_dist) << '\n';

    return 0;
}