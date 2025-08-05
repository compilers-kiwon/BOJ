#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)
#define MAX_DIR (4)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int, pair<int, int>> State;

int N, M;
char grid[MAX_SIZE][MAX_SIZE+1];

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int simulate(int e_row, int e_col) {
    queue<State> q;
    int num_of_collapse = 0;

    for (q.push({2, {e_row, e_col}}); !q.empty(); q.pop()) {
        int cur_power = q.front().first;
        int cur_row = q.front().second.first;
        int cur_col = q.front().second.second;

        for (int d = 0; d < MAX_DIR; d++) {
            for (int p = 1; p <= cur_power; p++) {
                bool wall = false;
                int adj_row = cur_row + (adj[d].d_row * p);
                int adj_col = cur_col + (adj[d].d_col * p);

                if (!IN_RANGE(1, adj_row, N) || !IN_RANGE(1, adj_col, M)) {
                    continue;
                }

                switch (grid[adj_row][adj_col]) {
                    case '|' :
                        wall = true;
                        break;
                    case '*' :
                        num_of_collapse++;
                        grid[adj_row][adj_col] = '.';
                        q.push({1, {adj_row, adj_col}});
                        break;
                    case '#' :
                        grid[adj_row][adj_col] = '*';
                        break;
                    default :
                        break;
                }

                if (wall == true) {
                    break;
                }
            }
        }
    }

    return num_of_collapse;
}

int input(int& src_row, int& src_col) {
    int ret = 0;

    cin >> N >> M;

    for (int row = 1; row <= N; row++) {
        cin >> &grid[row][1];

        for (int col = 1; col <= M; col++) {
            switch (grid[row][col]) {
                case '@' :
                    src_row = row, src_col = col;
                    break;
                case '*' :
                case '#' :
                    ret++;
                    break;
                default :
                    break;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int earthquake_row, earthquake_col;
    int num_of_buildings = input(earthquake_row, earthquake_col);
    int num_of_collapse = simulate(earthquake_row, earthquake_col);

    cout << num_of_collapse << ' '
            << num_of_buildings - num_of_collapse << '\n';

    return 0;
}