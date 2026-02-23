#include <iostream>
#include <map>

using namespace std;

#define MAX_DIR (3)

const struct {
    int dx, dy;
} adj[MAX_DIR] = {{0, 1}, {1, 0}, {1, 1}};

pair<int, int> input(map<pair<int, int>, int>& pos) {
    int N, A, B;

    for (cin >> N >> A >> B; N > 0; --N) {
        int x, y;
        cin >> x >> y;
        ++pos[{x, y}];
    }

    return {A, B};
}

int draw(map<pair<int, int>, int>& pos,
                int x, int y,int w, int h) {
    for (int d = 0; d < MAX_DIR; ++d) {
        int adj_x = x + (adj[d].dx * w);
        int adj_y = y + (adj[d].dy * h);
        auto it = pos.find({adj_x, adj_y});

        if (it == pos.end()) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum;
    pair<int, int> r;
    map<pair<int, int>, int> pos;

    r = input(pos), sum = 0;

    for (auto it = pos.begin(); it != pos.end(); ++it) {
        int x = it->first.first;
        int y = it->first.second;

        int A = r.first;
        int B = r.second;
        
        sum += draw(pos, x, y, A, B);
    }

    cout << sum << '\n';

    return 0;
}