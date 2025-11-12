#include <iostream>

using namespace std;

#define MAX_SIZE (50)

int Wr, Hr, Ws, Hs;
char obj[MAX_SIZE][MAX_SIZE+1];
char sky[MAX_SIZE][MAX_SIZE+1];

void read_image(int row_size, char grid[][MAX_SIZE+1]) {
    for (int row = 0; row < row_size; row++) {
        cin >> &grid[row][0];
    }
}

void input(void) {
    cin >> Wr >> Hr;
    read_image(Hr, obj);

    cin >> Ws >> Hs;
    read_image(Hs, sky);
}

pair<int, int> get_center_pos(void) {
    int c_row = (Hs - Hr) / 2;
    int c_col = (Ws - Wr) / 2;
    return {c_row, c_col};
}

bool is_matched(int s_row, int s_col) {
    for (int d_row = 0; d_row < Hr; d_row++) {
        for (int d_col = 0; d_col < Wr; d_col++) {
            if (obj[d_row][d_col] != sky[s_row+d_row][s_col+d_col]) {
                return false;
            }
        }
    }

    return true;
}

pair<int, int> get_matched_pos(void) {
    for (int row = 0; row <= Hs - Hr; row++) {
        for (int col = 0; col <= Ws - Wr; col++) {
            if (is_matched(row,col) == true) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    pair<int, int> obj_pos, center_pos;

    input();
    obj_pos = get_matched_pos();
    center_pos = get_center_pos();

    cout << obj_pos.second - center_pos.second << ' '
            << obj_pos.first - center_pos.first << '\n';
    
    return 0;
}