#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (100+1)

enum {
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
    MAX_DIR = 4
};

#define TURN_RIGHT(d) (((d)+1)%MAX_DIR)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int N, M, grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_DIR];

bool lock_up(int row, int col) {
    for (int d = RIGHT;;) {
        visited[row][col][d] = true;

        int adj_row = row + (adj[d].d_row * grid[row][col]);
        int adj_col = col + (adj[d].d_col * grid[row][col]);
        int adj_dir = TURN_RIGHT(d);

        if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, M)) {
            break;
        }

        if (visited[adj_row][adj_col][adj_dir] == true) {
            return true;
        }

        row = adj_row, col = adj_col, d = adj_dir;
    }

    return false;
}

void input(void) {
    cin >> N >> M;

    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= M; ++ col) {
            cin >> grid[row][col];
        }
    }
}

void init(void) {
    fill(&visited[0][0][0],
         &visited[0][0][0] + sizeof(visited),
         false);
}

int main (void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> candidates;

    input();

    for (int row = 1; row <= N; ++row) {
        init();
        
        if (lock_up(row, 1) == true) {
            candidates.push_back(row);
        }
    }

    cout << candidates.size() << '\n';

    for (int i = 0; i < candidates.size(); ++i) {
        cout << candidates[i] << ' ';
    }

    return 0;
}