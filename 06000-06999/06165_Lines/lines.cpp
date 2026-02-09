#include <iostream>
#include <set>
#include <tuple>
#include <cmath>

using namespace std;

typedef tuple<int, int, int> Line; // <sign, dy, dx>

#define MAX_SIZE (200+1)
#define get_sign(n) ((n)>0?1:-1)

set<Line> s;
pair<int, int> pos[MAX_SIZE];

int get_gcd(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);
    int mod = big % small;

    for (; mod != 0; mod = big % small) {
        big = small;
        small = mod;
    }

    return small;
}

Line get_line(int a, int b) {
    int x1 = pos[a].first;
    int y1 = pos[a].second;

    int x2 = pos[b].first;
    int y2 = pos[b].second;

    int dy = y1 - y2;
    int dx = x1 - x2;
    
    if (dx == 0) {
        return {0, 0, 0};
    }

    if (dy == 0) {
        return {0, 0, 1};
    }

    int sign = get_sign(dy) * get_sign(dx);
    dx = abs(dx), dy = abs(dy);

    int gcd = get_gcd(dx, dy);
    return {sign, dy / gcd, dx / gcd};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            s.insert(get_line(i, j));
        }
    }

    cout << s.size() << '\n';

    return 0;
}