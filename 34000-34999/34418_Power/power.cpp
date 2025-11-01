#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (30)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

typedef pair<int, int> Pos;

int N, M;
char grid[MAX_SIZE][MAX_SIZE+1];

bool get_power(int row, int col) {
    for (int d_row = -1; d_row <= 1; d_row++) {
        for (int d_col = -1; d_col <= 1; d_col++) {
            int adj_row = row + d_row;
            int adj_col = col + d_col;

            if (!IN_RANGE(0, adj_row, N) || !IN_RANGE(0, adj_col, M)) {
                continue;
            }

            if (grid[adj_row][adj_col] == 'T') {
                return true;
            }
        }
    }

    return false;
}

void input(void) {
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        cin >> &grid[row][0];
    }
}

void simulate(vector<Pos>& not_powred) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (grid[row][col] == 'b' && get_power(row, col) == false) {
                not_powred.push_back({row, col});
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> not_powered;

    input();
    simulate(not_powered);

    if (not_powered.empty()) {
        cout << "True\n";
    } else {
        cout << "False\n";

        for (int i = 0; i < not_powered.size(); i++) {
            cout << not_powered[i].first << ' ' << not_powered[i].second << '\n';
        }
    }

    return 0;
}