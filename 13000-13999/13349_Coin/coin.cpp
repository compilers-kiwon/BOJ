#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)
#define MAX_DIR (4)
#define INF (0x7FFFFFFF)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int, pair<int, int>> State; // <ladder, <row, col>>
int M, N, grid[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

const struct {int d_row, d_col;}
    adj[MAX_DIR] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int simulate(void) {
    priority_queue<State> pq;

    for (pq.push({0, {1, 1}}), visited[1][1] = 0; !pq.empty();) {
        int cur_ladder = -pq.top().first;
        int cur_row = pq.top().second.first;
        int cur_col = pq.top().second.second;

        pq.pop();

        if (cur_row == M && cur_col == N) {
            break;
        }

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, M) || !IN_RANGE(1, adj_col, N)) {
                continue;
            }

            int cur_height = grid[cur_row][cur_col];
            int adj_height = grid[adj_row][adj_col];
            int adj_ladder = max(max(0, adj_height - cur_height), cur_ladder);

            if (adj_ladder < visited[adj_row][adj_col]) {
                visited[adj_row][adj_col] = adj_ladder;
                pq.push({-adj_ladder, {adj_row, adj_col}});
            }
        }
    }

    return visited[M][N];
}

void input(void) {
    cin >> M >> N;

    for (int row = 1; row <= M; row++) {
        for (int col = 1; col <= N; col++) {
            cin >> grid[row][col];
            visited[row][col] = INF;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}