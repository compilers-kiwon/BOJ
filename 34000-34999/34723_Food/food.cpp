#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define NUM_OF_FOODS (3)
#define MAX_VALUE (1000000000)

int get_value(const vector<int>& f) {
    int ret = 1;

    for (int i = 0; i < f.size() - 1; ++i) {
        ret *= (f[i] + f[i+1]);
    }

    return ret;
}

void dfs(const vector<int>& upper, int X,
            vector<int>& selected, int cur_food, int& min_diff) {
    if (cur_food == upper.size()) {
        min_diff = min(min_diff, abs(get_value(selected) - X));
        return;
    }

    for (int i = 1; i <= upper[cur_food]; ++i) {
        selected.push_back(i);
        dfs(upper, X, selected, cur_food + 1, min_diff);
        selected.pop_back();
    }
}

int input(vector<int>& food) {
    int X;

    for (int i = 1; i <= NUM_OF_FOODS; ++i) {
        int n;
        cin >> n;
        food.push_back(n);
    }

    cin >> X;
    return X;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, min_diff;
    vector<int> available, selected;

    X = input(available), min_diff = MAX_VALUE;
    dfs(available, X, selected, 0, min_diff);
    cout << min_diff << '\n';

    return 0;
}