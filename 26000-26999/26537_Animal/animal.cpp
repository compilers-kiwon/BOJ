#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

void input(vector<Pos>& animals) {
    int z;

    for (cin >> z; z > 0; --z) {
        int x, y;
        cin >> x >> y;
        animals.push_back({x, y});
    }

    sort(animals.begin(), animals.end());
}

void simulate(const vector<Pos>& animals, int& a1, int& a2) {
    double min_dist = 100000000.0;

    for (int i = 0; i < animals.size() - 1; ++i) {
        for (int j = i+1; j < animals.size(); ++j) {
            int dx = animals[i].first - animals[j].first;
            int dy = animals[i].second - animals[j].second;
            double cur_dist = sqrt((dx * dx) + (dy * dy));

            if (cur_dist < min_dist) {
                min_dist = cur_dist;
                a1 = i, a2 = j;
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; --n) {
        vector<Pos> animals;
        int idx1, idx2;

        input(animals);
        simulate(animals, idx1, idx2);
        
        Pos& p1 = animals[idx1];
        Pos& p2 = animals[idx2];

        cout << p1.first << ' ' << p1.second << ' '
                << p2.first << ' ' << p2.second << '\n';
    }

    return 0;
}