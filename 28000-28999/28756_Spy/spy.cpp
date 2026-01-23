#include <iostream>
#include <cmath>

using namespace std;

#define INF (1000000.0f)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    double xs, ys, xt, yt, min_dist;

    for (cin >> xs >> ys >> xt >> yt >> n, min_dist = INF; n > 0; --n) {
        double x, y, t, d1, d2;

        cin >> x >> y >> t;

        d1 = sqrt((xs - x) * (xs - x) + (ys - y) * (ys - y));
        d2 = sqrt((xt - x) * (xt - x) + (yt - y) * (yt - y));
        min_dist = min(min_dist, d1 + d2 + t);
    }

    cout << fixed; cout.precision(9);
    cout << min_dist << '\n';

    return 0;
}