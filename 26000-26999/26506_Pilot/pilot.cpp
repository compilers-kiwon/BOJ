#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (1000000*2)

void input(vector<int>& res) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int s;
        cin >> s;
        res.push_back(s);
    }
}

int simulate(const vector<int>& s) {
    int ret = INF;

    for (int h = 0, t = s.size() - 1; h < t; ++h, --t) {
        ret = min(ret, s[h] + s[t]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> s;

    input(s);
    sort(s.begin(), s.end());
    cout << simulate(s) << '\n';

    return 0;
}