#include <iostream>
#include <queue>

using namespace std;

#define MAX_DIR (8)
#define MAX_SIZE (100+1)
#define INF (MAX_SIZE*MAX_SIZE)

typedef pair<int, int> Pos;

int R, C, visited[MAX_SIZE][MAX_SIZE];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                  {1, 2}, {2, 1}, {2, -1}, {1, -2}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool input(int& Gr, int& Gc, int& Lr, int& Lc) {
    if (!(cin >> R >> C)) {
        return false;
    }

    for (int row = 1; row <= R; row++) {
        fill(&visited[row][1], &visited[row][C+1], INF);
    }

    cin >> Gr >> Gc >> Lr >> Lc;

    return true;
}

int simulate(int Gr, int Gc, int Lr, int Lc) {
    int ret;
    queue<Pos> q;

    for (q.push({Gr, Gc}), visited[Gr][Gc] = 0, ret = INF; !q.empty(); q.pop()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        int cur_steps = visited[cur_row][cur_col];

        if (cur_row == Lr && cur_col == Lc) {
            ret = cur_steps;
            break;
        }

        for (int i = 0; i < MAX_DIR; i++) {
            int adj_row = cur_row + adj[i].d_row;
            int adj_col = cur_col + adj[i].d_col;

            if (!IN_RANGE(1, adj_row, R) || !IN_RANGE(1, adj_col, C)) {
                continue;
            }

            if (visited[adj_row][adj_col] != INF) {
                continue;
            }

            q.push({adj_row, adj_col});
            visited[adj_row][adj_col] = cur_steps + 1;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int Gr, Gc, Lr, Lc, ans;

        if (input(Gr, Gc, Lr, Lc) == false) {
            break;
        }

        ans = simulate(Gr, Gc, Lr, Lc);
        
        if (ans != INF) {
            cout << ans << '\n';
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}