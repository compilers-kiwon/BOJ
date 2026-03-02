#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

#define NUM_OF_PLAYERS (3)

bool simulate(const vector<Pos>& p) {
    int prev_dx = p[1].first - p[0].first;
    int prev_dy = p[1].second - p[0].second;

    for (int i = 1; i < p.size() - 1; ++i) {
        int cur_dx = p[i+1].first - p[i].first;
        int cur_dy = p[i+1].second - p[i].second;

        if (prev_dx * cur_dy != prev_dy * cur_dx) {
            return false;
        }
    }

    return true;
}

void input(vector<Pos>& p) {
    for (int i = 0; i < NUM_OF_PLAYERS; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> p;

    input(p);
    sort(p.begin(), p.end());

    do {
        if (simulate(p) == true) {
            cout << "WHERE IS MY CHICKEN?\n";
            return 0;
        }
    } while(next_permutation(p.begin(), p.end()) == true);

    cout << "WINNER WINNER CHICKEN DINNER!\n";

    return 0;
}