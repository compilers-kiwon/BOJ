#include <iostream>
#include <map>
#include <cmath>

using namespace std;

enum {
    Q1 = 0,
    Q2 = 1,
    Q3 = 2,
    Q4 = 3,
    MAX_QUADRANTS = 4,
};

enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    MAX_DIR = 4,
};

typedef pair<int, int> Gradient;

int axis[MAX_DIR];
map<Gradient, int> quad[MAX_QUADRANTS];

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

Gradient get_gradient(int x, int y) {
    int g = get_gcd(x, y);
    return {x / g, y / g};
}

int get_dir(int x, int y) {
    int ret;

    if (x == 0) {
        ret = (y>0)?UP:DOWN;
    } else {
        ret = (x>0)?RIGHT:LEFT;
    }

    return ret;
}

int get_quadrant(int x, int y) {
    int ret;

    if (x > 0) {
        ret = (y>0)?Q1:Q4;
    } else {
        ret = (y>0)?Q2:Q3;
    }

    return ret;
}

int simulate(int x, int y) {
    int ret;

    if (x == 0 || y == 0) {
        ret = ++axis[get_dir(x, y)];
    } else {
        int q = get_quadrant(x, y);
        ret = ++quad[q][get_gradient(abs(x), abs(y))];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, max_cnt;

    for (cin >> N, max_cnt = 0; N > 0; --N) {
        int x, y;
        cin >> x >> y;
        max_cnt = max(max_cnt, simulate(x, y));
    }

    cout << max_cnt << '\n';

    return 0;
}