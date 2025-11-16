#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define get_idx(c) ((int)((c)-'A'))

typedef pair<int, int> Pos;

Pos get_pos(const string& s) {
    return {get_idx(s.front()), get_idx(s.back())};
}

int get_dist(const Pos& p1, const Pos& p2) {
    return (abs(p1.first-p2.first) + abs(p1.second - p2.second));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    int N, sum_of_dist;
    Pos cur;

    cin >> N >> s;
    cur = get_pos(s);
    sum_of_dist = 0;

    for (int i = 2; i <= N; i++) {
        Pos next;

        cin >> s;
        next = get_pos(s);
        
        sum_of_dist += get_dist(cur, next);
        cur = next;
    }

    cout << sum_of_dist << '\n';

    return 0;
}