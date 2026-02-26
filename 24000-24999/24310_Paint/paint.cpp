#include <iostream>
#include <set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C, D, ans;
    set<pair<int, int>> s;

    cin >> A >> B >> C >> D;
    s.insert({min(A, B), max(A, B)});
    s.insert({min(C, D), max(C, D)});

    pair<int, int> p1, p2;

    p1 = *s.begin();
    p2 = *s.rbegin();

    if (p1.first <= p2.first && p2.first <= p1.second) {
        ans = max(p1.second, p2.second) - p1.first + 1;
    } else {
        ans = (p1.second - p1.first + 1) + (p2.second - p2.first + 1);
    }

    cout << ans << '\n';

    return 0;
}