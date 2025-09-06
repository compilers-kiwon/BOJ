#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> Pos; // <row, col>

#define MAX_DIR (4)

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int simulate(vector<string>& box, int row, int col) {
    int ret = 0;
    queue<Pos> q;

    for (q.push({row, col}), box[row][col] = '#'; !q.empty(); q.pop(), ret++) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (box[adj_row][adj_col] == '.') {
                q.push({adj_row, adj_col}), box[adj_row][adj_col] = '#';
            }
        }
    }

    return ret;
}

void input(vector<string>& box, int& row_size, int& col_size) {
    cin >> row_size >> col_size;

    for (int row = 0; row < row_size; row++) {
        string str;
        cin >> str;
        box.push_back(str);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; n--) {
        int r, c;
        vector<string> box;
        int num_of_sections, num_of_spaces;

        input(box, r, c);
        num_of_sections = num_of_spaces = 0;

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                if (box[row][col] == '.') {
                    num_of_spaces += simulate(box, row, col);
                    num_of_sections++;
                }
            }
        }

        cout << num_of_sections << ((num_of_sections==1)?" section, ":" sections, ")
                << num_of_spaces << ((num_of_spaces==1)?" space\n":" spaces\n");
    }

    return 0;
}