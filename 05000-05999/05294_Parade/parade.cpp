#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_DIFF (2)

void input(vector<pair<int, string>>& p) {
    int h;
    string n;

    for (; cin >> n >> h;) {
        p.push_back({h, n});
    }
}

void simulate(const vector<pair<int, string>>& p) {
    for (int i = 0; i < p.size() - 1;) {
        int small = p[i].first;
        int big = p[i+1].first;

        if (big - small <= MAX_DIFF) {
            cout << p[i].second << ' ' << p[i+1].second << '\n';
            i += 2;
        } else {
            i += 1;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<pair<int, string>> pirates;

    input(pirates);
    sort(pirates.begin(), pirates.end());
    simulate(pirates);

    return 0;
}