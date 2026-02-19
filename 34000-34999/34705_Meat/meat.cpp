#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (5)

void get_all_selections(int cur, vector<int>& selected, vector<vector<int>>& all) {
    if (cur == MAX_SIZE) {
        all.push_back(selected);
        return;
    }

    selected.push_back(cur);
    get_all_selections(cur + 1, selected, all);
    selected.pop_back();

    get_all_selections(cur + 1, selected, all);
}

int get_total_weight(const vector<int>& a, const vector<int>& used) {
    int ret = 0;

    for (int i = 0; i < used.size(); ++i) {
        ret += a[used[i]];
    }

    return ret;
}

bool simulate(int X, int Y, const vector<int>& a, const vector<vector<int>>& all) {
    for (int i = 0; i < all.size(); ++i) {
        int total_weight = get_total_weight(a, all[i]);

        if (X <= total_weight && total_weight <= Y) {
            return true;
        }
    }

    return false;
}

void input(int& X, int& Y, vector<int>& a) {
    cin >> X >> Y;

    for (int i = 0; i < MAX_SIZE; ++i) {
        int w;
        cin >> w;
        a.push_back(w);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    vector<int> s;
    vector<vector<int>> all;

    for (cin >> T, get_all_selections(0, s, all); T > 0; --T) {
        int X, Y;
        vector<int> a;

        input(X, Y, a);
        cout << (simulate(X, Y, a, all)?"YES":"NO") << '\n';
    }

    return 0;
}