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

    char p, grid[GRID_SIZE][GRID_SIZE+1];

    cin >> p;

    for (int row = 0; row < GRID_SIZE; row++) {
        cin >> &grid[row][0];
    }

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 'E') {
                grid[row][col] = p;

                for (int i = 0; i < win.size(); i++) {
                    if (win_game(grid, p, win[i]) == true) {
                        cout << row + 1 << ' ' << col + 1 << '\n';
                        return 0;
                    }
                }

                grid[row][col] = 'E';
            }
        }
    }
    
    return 0;
}