#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> Query;

vector<Query> q;
map<int, int> haybles;

void input(void) {
    int N, Q;

    for (cin >> N >> Q; N > 0; --N) {
        int pos;
        cin >> pos;
        haybles[pos] = 1;
    }

    for (; Q > 0; --Q) {
        int left, right;
        cin >> left >> right;
        q.push_back({left, right});
    }

    int prev = 0;

    for (auto it = haybles.begin(); it != haybles.end(); ++it) {
        it->second += prev;
        prev = it->second;
    }

    haybles[1000000000+1] = prev + 1;
}

void do_query(void) {

    for (int i = 0; i < q.size(); i++) {
        auto left = haybles.lower_bound(q[i].first);
        auto right = haybles.upper_bound(q[i].second);
        cout << right->second - left->second << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    do_query();

    return 0;
}