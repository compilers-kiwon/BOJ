#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_SIZE (8)
#define INF (0x7FFFFFFF)

typedef pair<int, int> Pos;

#define row first
#define col second

Pos start, target;
vector<vector<Pos>> shortest;
int shortest_length;
int visited[MAX_SIZE+1][MAX_SIZE+1];

void dfs(Pos cur_pos, int cur_steps, vector<Pos>& p) {
    if (cur_pos == target) {
        if (shortest.empty() || cur_steps <= shortest.front().size()) {
            if (!shortest.empty() && cur_steps < shortest.front().size()) {
                shortest.clear();
            }

            shortest.push_back(p);
            shortest_length = cur_steps;
        }
        return;
    }

    if (cur_steps >= shortest_length) {
        return;
    }

    for (int adj_row = 1; adj_row <= MAX_SIZE; adj_row++) {
        for (int adj_col = 1; adj_col <= MAX_SIZE; adj_col++) {
            int d_row = abs(adj_row - cur_pos.row);
            int d_col = abs(adj_col - cur_pos.col);

            if ((d_row == 2 && d_col == 1) || (d_row == 1 && d_col == 2)) {
                if ((cur_steps + 1) < visited[adj_row][adj_col]) {
                    visited[adj_row][adj_col] = cur_steps + 1;
                    p.push_back({adj_row, adj_col});

                    dfs({adj_row, adj_col}, cur_steps + 1, p);

                    p.pop_back();
                    visited[adj_row][adj_col] = INF;
                }
            }
        }
    }
}

void print(void) {
    for (int i = 0; i < shortest.size(); i++) {
        for (int j = 0; j < shortest[i].size(); j++) {
            int row = shortest[i][j].row;
            int col = shortest[i][j].col;

            cout << (char)((int)'a' + row - 1) << col <<
                    ((j==(shortest[i].size()-1))?"\n":" -> ");
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int row = 1; row <= MAX_SIZE; row++) {
        for (int col = 1; col <= MAX_SIZE; col++) {
            visited[row][col] = INF;
        }
    }

    char r1, r2;
    int c1, c2;
    vector<Pos> p;

    cin >> r1 >> c1 >> r2 >> c2;

    start = {(int)(r1-'a'+1), c1};
    target = {(int)(r2-'a'+1), c2};

    p.push_back(start);
    visited[start.row][start.col] = 1;

    shortest_length = INF;
    dfs(start, 1, p);
    print();

    return 0;
}