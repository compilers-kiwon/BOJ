#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE (50+1)
#define MAX_DIR (4)

typedef pair<int, int> Pos; // <row, col>

int R, S;
char grid[MAX_SIZE][MAX_SIZE+1];
vector<vector<Pos>> connected;
priority_queue<pair<int, int>> pq;

static inline bool in_range(int MIN, int n, int MAX) {
    return ((MIN)<=(n) && (n)<=(MAX));
}

void dfs(int cur_row, int cur_col, vector<Pos>& p) {
    if (!in_range(1, cur_row, R) || !in_range(1, cur_col, S)) {
        return;
    }

    if (grid[cur_row][cur_col] == '0') {
        return;
    }

    grid[cur_row][cur_col] = '0';
    p.push_back({cur_row, cur_col});

    const struct {int d_row, d_col;}
        adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        dfs(adj_row, adj_col, p);
    }
}

void analyze(void) {
    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= S; col++) {
            if (grid[row][col] == '1') {
                vector<Pos> cur;

                dfs(row, col, cur);
                connected.push_back(cur);
                pq.push({-(cur.size()), connected.size() - 1});
            }
        }
    }
}

void simulate(void) {
    for (char i = '1'; !pq.empty(); i++, pq.pop()) {
        int idx = pq.top().second;
        const vector<Pos>& cur = connected[idx];

        for (int j = 0; j < cur.size(); j++) {
            int row = cur[j].first;
            int col = cur[j].second;
            
            grid[row][col] = i;
        }
    }
}

void print(void) {
    for (int row = 1; row <= R; row++) {
        cout << &grid[row][1] << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> R >> S;

    for (int row = 1; row <= R; row++) {
        cin >> &grid[row][1];
    }

    analyze();
    simulate();
    print();

    return 0;
}