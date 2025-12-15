#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> Pos; // <x, y>

void input(vector<Pos>& star, set<Pos>& observed) {
    int m, n;

    for (cin >> m; m > 0; m--) {
        int x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    for (cin >> n; n > 0; n--) {
        int x, y;
        cin >> x >> y;
        observed.insert({x, y});
    }
}

Pos simulate(const vector<Pos>& star, const set<Pos>& observed) {
    Pos ret;
    Pos ref = star.front();

    for (auto it = observed.begin(); it != observed.end(); it++) {
        int cnt = 0;
        Pos offset = {it->first - ref.first, it->second - ref.second};
        
        for (int i = 0; i < star.size(); i++, cnt++) {
            Pos cur = star[i];
            Pos shifted = {cur.first + offset.first, cur.second + offset.second};

            if (observed.find(shifted) == observed.end()) {
                break;
            }
        }

        if (cnt == star.size()) {
            ret = offset;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos offset;
    vector<Pos> star;
    set<Pos> observed;

    input(star, observed);
    offset = simulate(star, observed);
    cout << offset.first << ' ' << offset.second << '\n';

    return 0;
}