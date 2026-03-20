#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (1000+1)
#define INF (MAX_SIZE*MAX_SIZE)

typedef tuple<int, int, int> State; // <row, col, dist>
typedef tuple<int, int, int> Rent; // <row, col, cost>

int N, M, dist[MAX_SIZE][MAX_SIZE];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(vector<Rent>& r, queue<State>& q) {
    int R, C;

    cin >> N >> M >> R >> C;

    for (int row = 1; row <= N; ++row) {
        fill(&dist[row][1], &dist[row][M+1], INF);
    }

    for (int i = 1; i <= R; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        r.push_back({a, b, p});
    }

    for (int i = 1; i <= C; ++i) {
        int c, d;
        cin >> c >> d;
        q.push({c, d, 0}), dist[c][d] = 0;
    }
}

void simulate(queue<State>& q) {
    for (; !q.empty(); q.pop()) {
        auto [row, col, di] = q.front();

        for (int d = 0; d < MAX_DIR; ++d) {
            int adj_row = row + adj[d].d_row;
            int adj_col = col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, M)) {
                continue;
            }

            if (di + 1 >= dist[adj_row][adj_col]) {
                continue;
            }

            dist[adj_row][adj_col] = di + 1;
            q.push({adj_row, adj_col, di + 1});
        }
    }
}

int find_min_cost(const vector<Rent>& r) {
    int ret = INF;

    for (int i = 0; i < r.size(); ++i) {
        auto [row, col, cost] = r[i];
        ret = min(ret, dist[row][col] * cost);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Rent> r;
    queue<State> q;

    input(r, q);
    simulate(q);
    cout << find_min_cost(r) << '\n';

    return 0;
}