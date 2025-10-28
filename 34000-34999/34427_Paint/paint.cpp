#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (1000)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

typedef pair<int, int> Pos;

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int w, h, x, y;
int grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void input(void) {
    cin >> w >> h >> x >> y;
    
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            cin >> grid[row][col];
        }
    }
}

void dfs(int row, int col, int color, vector<Pos>& p) {
    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = row + adj[d].d_row;
        int adj_col = col + adj[d].d_col;

        if (!IN_RANGE(0, adj_row, h) || !IN_RANGE(0, adj_col, w)) {
            continue;
        }

        if (visited[adj_row][adj_col] == true) {
            continue;
        }

        if (grid[adj_row][adj_col] != color) {
            continue;
        }

        p.push_back({adj_row, adj_col});
        visited[adj_row][adj_col] = true;
        dfs(adj_row, adj_col, color, p);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> group;

    input();

    group.push_back({y, x});
    visited[y][x] = true;
    
    dfs(y, x, grid[y][x], group);
    sort(group.begin(), group.end());

    for (int i = 0; i < group.size(); i++) {
        cout << group[i].second << ' '
                << group[i].first << '\n';
    }

    return 0;
}