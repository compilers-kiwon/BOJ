#include <iostream>
#include <string>
#include <set>

using namespace std;

#define MAX_DIR (4)
#define get_dir(c) ((c)=='U'?0:(c)=='D'?1:(c)=='R'?2:3)

const struct {
    int dx, dy;
} adj[MAX_DIR] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef pair<int, int> Pos;

void input(set<Pos>& b, string& c) {
    int N, K;

    for (cin >> N >> K; N > 0; --N) {
        Pos p;
        cin >> p.first >> p.second;
        b.insert(p);
    }

    cin >> c;
}

Pos simulate(const set<Pos>& b, const string& c) {
    Pos p = {0, 0};

    for (int i = 0; i < c.length(); i++) {
        int d = get_dir(c[i]);
        Pos adj_pos = {p.first + adj[d].dx, p.second + adj[d].dy};

        if (b.find(adj_pos) == b.end()) {
            p = adj_pos;
        }
    }

    return p;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string in;
    set<Pos> blocked;
    Pos p;

    input(blocked, in);
    p = simulate(blocked, in);
    cout << p.first << ' ' << p.second << '\n';

    return 0;
}
