#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pos;

#define row first
#define col second

typedef pair<int, Pos> State;

#define MAX_DIR (4)
#define MAX_SIZE (100+1)
#define INF (0x7FFFFFFF)

int W, H, dp[MAX_SIZE][MAX_SIZE];
char grid[MAX_SIZE][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input(Pos& init) {
    cin >> W >> H;

    for (int row = 1; row <= H; row++) {
        cin >> &grid[row][1];
        fill(&dp[row][1], &dp[row][W+1], INF);

        for (int col = 1; col <= W; col++) {
            if (grid[row][col] == '*') {
                init.row = row, init.col = col;
            }
        }
    }
}

int simulate(const Pos& start) {
    int ret;
    priority_queue<State> pq;

    for (ret = INF, pq.push({0, start}); !pq.empty();) {
        int cur_doors = -pq.top().first;
        Pos cur_pos = pq.top().second;

        pq.pop();
        
        if (grid[cur_pos.row][cur_pos.col] == 'E') {
            ret = cur_doors;
            break;
        }

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_pos.row + adj[d].d_row;
            int adj_col = cur_pos.col + adj[d].d_col;

            if (grid[adj_row][adj_col] == '#') {
                continue;
            }

            int adj_doors = cur_doors + (grid[adj_row][adj_col]=='D'?1:0);

            if (adj_doors < dp[adj_row][adj_col]) {
                dp[adj_row][adj_col] = adj_doors;
                pq.push({-adj_doors, {adj_row, adj_col}});
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos p;
    int min_num_of_doors;

    input(p);
    min_num_of_doors = simulate(p);

    if (min_num_of_doors == INF) {
        cout << "NOT POSSIBLE\n";
    } else {
        cout << min_num_of_doors << '\n';
    }

    return 0;
}