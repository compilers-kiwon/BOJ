#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;

void input(vector<string>& grid) {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
}

int get_size_of_pattern(const vector<string>& grid, int size) {
    int ret = size;

    for (int p = 1; p <= size; p++) {
        bool repeated = true;

        for (int pos = 0; pos + p < size; pos++) {
            if (grid[pos] != grid[pos+p]) {
                repeated = false;
                break;
            }
        }

        if (repeated == true) {
            ret = p;
            break;
        }
    }

    return ret;
}

void rotate_grid(const vector<string>& src, vector<string>& dst) {
    for (int col = 0; col < C; col++) {
        string buf;

        for (int row = 0; row < R; row++) {
            buf.push_back(src[row][col]);
        }

        dst.push_back(buf);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h, w;
    vector<string> grid, rotated;

    input(grid);
    h = get_size_of_pattern(grid, R);

    rotate_grid(grid, rotated);
    w = get_size_of_pattern(rotated, C);

    cout << h * w << '\n';
    return 0; 
}