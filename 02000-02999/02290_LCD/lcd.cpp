#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define _7_SEGMENT (7)
#define MAX_ROW_SIZE (23)
#define MAX_COL_SIZE (130)

#define RIGHT (0)
#define DOWN (1)
#define MAX_DIR (2)

const int _7_segment[9+1] = {
    0x77, 0x24, 0x5D, 0x6D, 0x2E, 0x6B, 0x7B, 0x25, 0x7F, 0x6F
};

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{0,1}, {1,0}};

const int line_dir[_7_SEGMENT] = {
    RIGHT, DOWN, DOWN, RIGHT, DOWN, DOWN, RIGHT
};

int s;
char screen[MAX_ROW_SIZE][MAX_COL_SIZE];
string n;
vector<int> digits;

pair<int,int> get_pos(int idx) {
    pair<int,int> ret;

    switch (idx) {
        case 0:ret={0,1};break;
        case 1:ret={1,0};break;
        case 2:ret={1,s+1};break;
        case 3:ret={s+1,1};break;
        case 4:ret={s+2,0};break;
        case 5:ret={s+2,s+1};break;
        case 6:ret={s+s+2,1};break;
        default:break;
    }

    return ret;
}

void clear_screen(int num_of_digits) {
    for (int row = 0; row < (2*s + 3); row++) {
        for (int col = 0; col < (s + 2 + 1) * num_of_digits; col++) {
            screen[row][col] =
                (col==(s+2+1)*num_of_digits-1)?'\0':' ';
        }
    }
}

void draw_line(int row, int col, int idx) {
    int dir = line_dir[idx];
    char c = (dir==DOWN)?'|':'-';
    int d_row = adj[dir].d_row;
    int d_col = adj[dir].d_col;

    for (int i = 0; i < s; i++) {
        int adj_row = row + (i * d_row);
        int adj_col = col + (i * d_col);

        screen[adj_row][adj_col] = c;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>s>>n;

    clear_screen(n.length());

    for (int i = 0; i < n.length(); i++) {
        int num = (int)(n[i] - '0');
        digits.push_back(_7_segment[num]);
    }

    int s_row = 0;
    int s_col = 0;

    for (int i = 0; i < digits.size(); i++) {
        for (int j = 0; j < _7_SEGMENT; j++) {
            if ((digits[i] & (1<<j)) == 0) {
                continue;
            }

            pair<int,int> d = get_pos(j);
            int row_offset = d.first;
            int col_offset = d.second;

            draw_line(s_row + row_offset, s_col + col_offset, j);
        }

        s_col += s + 2 + 1;
    }

    for (int row = 0; row < (2*s + 3); row++) {
        cout<<&screen[row][0]<<'\n';
    }

    return 0;
}