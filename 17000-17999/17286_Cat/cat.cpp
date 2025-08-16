#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

#define MAX_SIZE (4)

double get_distance(const vector<Pos>& p) {
    double ret = 0.0;

    for (int i = 0; i < (p.size() - 1); i++) {
        int x1 = p[i].first;
        int y1 = p[i].second;
        int x2 = p[i+1].first;
        int y2 = p[i+1].second;

        ret += sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    }

    return ret;
}

void input(vector<Pos>& p) {
    for (int i = 0; i < MAX_SIZE; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> p;
    double min_dist;

    input(p);
    sort(p.begin() + 1, p.end());
    min_dist = 1000000.0;

    do {
        min_dist = min(min_dist, get_distance(p));
    } while (next_permutation(p.begin() + 1, p.end()) == true);

    cout << (int)min_dist << '\n';
    return 0;
}