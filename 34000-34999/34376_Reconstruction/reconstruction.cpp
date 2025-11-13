#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (100000+1)

enum {
    UNNECESSARY = 0,
    BUILT = 1,
    IMPOSSIBLE = 2,
};

const string str[] = {"UNNECESSARY", "BUILT", "IMPOSSIBLE"};

typedef long long int int64;

int n, m, parent[MAX_SIZE];
int64 w[MAX_SIZE];

void init(void) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i], parent[i] = i;
    }
}

int find_parent(int cur) {
    int& ret = parent[cur];

    if (ret != cur) {
        ret = find_parent(ret);
    }

    return ret;
}

int simulate(int a, int b, int64 c) {
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);

    if (a_parent == b_parent) {
        return UNNECESSARY;
    }

    if (w[a_parent] < c || w[b_parent] < c) {
        return IMPOSSIBLE;
    }

    parent[max(a_parent,b_parent)] = min(a_parent,b_parent);
    w[min(a_parent,b_parent)] += w[max(a_parent,b_parent)] - (2LL * c);

    return BUILT;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << str[simulate(a, b, (int64)c)] << '\n';
    }

    return 0;
}