#include <iostream>
#include <vector>

using namespace std;

#define GRID_SIZE (3)

typedef pair<int, int> Pos;

const vector<vector<Pos>> win = {
  {{0, 0}, {0, 1}, {0, 2}},
  {{1, 0}, {1, 1}, {1, 2}},
  {{2, 0}, {2, 1}, {2, 2}},
  {{0, 0}, {1, 0}, {2, 0}},
  {{0, 1}, {1, 1}, {2, 1}},
  {{0, 2}, {1, 2}, {2, 2}},
  {{0, 0}, {1, 1}, {2, 2}},
  {{0, 2}, {1, 1}, {2, 0}},
};

bool win_game(char grid[][GRID_SIZE+1], char p, const vector<Pos>& pattern) {
    for (int i = 0; i < pattern.size(); i++) {
        int row = pattern[i].first;
        int col = pattern[i].second;

        if (grid[row][col] != p) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char grid[GRID_SIZE][GRID_SIZE+1];

    for (int row = 0; row < GRID_SIZE; row++) {
        cin >> &grid[row][0];
    }

    for (int i = 0; i < win.size(); i++) {
        char player[2] = {'X', 'O'};

        for (int j = 0; j < 2; j++) {
            if (win_game(grid, player[j], win[i])) {
                cout << player[j] << '\n';
                return 0;
            }
        }
    }

    cout << "N\n";
    return 0;
}