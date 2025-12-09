#include <iostream>

using namespace std;

typedef unsigned long long uint64; 
typedef pair<uint64, uint64> Node; // <p, q>

uint64 dfs(uint64 p, uint64 q) {
    if (p == 1 && q == 1) {
        return 1;
    }

    uint64 pos;

    if (p < q) { // left child
        q -= p, pos = 0;
    } else {
        p -= q, pos = 1;
    }

    return ((2 * dfs(p ,q)) + pos);
}

Node dfs(uint64 n) {
    if (n == 1) {
        return {1, 1};
    }

    uint64 p, q;
    Node parent = dfs(n / 2ULL);

    if ((n%2ULL) == 0) { // left child
        p = parent.first;
        q = parent.first + parent.second;
    } else {
        p = parent.first + parent.second;
        q = parent.second;
    }

    return {p, q};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        Node e;
        uint64 id, n, p, q;

        cin >> id;
        cout << "Case #" << t << ": ";
        
        if (id == 1UL) {
            cin >> n;
            e = dfs(n);
            cout << e.first << ' ' << e.second << '\n';
        } else {
            cin >> p >> q;
            cout << dfs(p, q) << '\n';
        }
    }

    return 0;
}