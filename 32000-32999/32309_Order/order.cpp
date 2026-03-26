#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

typedef tuple<int, int, int> Clue;

#define MAX_SIZE (10)

int simulate(const vector<int>& order, const vector<Clue>& c) {
    int pos[MAX_SIZE];

    for (int i = 0; i < order.size(); ++i) {
        pos[order[i]] = i;
    }

    for (int i = 0; i < c.size(); ++i) {
        auto [a, x, y] = c[i];

        switch (a) {
            case 1:
                if (pos[x] > pos[y]) {
                    return 0;
                }
                break;
            case 2:
                if (pos[x] < pos[y]) {
                    return 0;
                }
                break;
            case 3:
                if (abs(pos[x] - pos[y]) == 1) {
                    return 0;
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    return 1;
}

void input(vector<int>& order, vector<Clue>& clues) {
    int n, c;

    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        order.push_back(i);
    }

    for (int i = 0; i < c; ++i) {
        int a;
        char x, y;

        cin >> a >> x >> y;
        clues.push_back({a, (int)(x - 'A'), (int)(y - 'A')});
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> order;
    vector<Clue> c;
    int cnt;

    input(order, c), cnt = 0;

    do {
        cnt += simulate(order, c);
    } while (next_permutation(order.begin(), order.end()) == true);

    cout << cnt << '\n';

    return 0;
}