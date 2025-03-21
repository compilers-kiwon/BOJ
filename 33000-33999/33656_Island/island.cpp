#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

enum {UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, MAX_DIR = 4};

const struct {
    int d_row, d_col;
} adj[] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

typedef pair<int,int> Pos;

const char LAND = '#';
const char SEA = '.';
const char START = 'S';

Pos input(vector<string>& grid) {
    int R, C;
    Pos ret;

    cin>>R>>C;

    for (int row = 0; row < R; row++) {
        string s;

        cin>>s;
        grid.push_back(s);

        if (s.find(START) != string::npos) {
            ret = {row, s.find(START)};
        }
    }

    return ret;
}

int simulate(const Pos& s, vector<string>& grid) {
    int ret = 0;
    queue<Pos> q;

    q.push(s);
    grid[s.first][s.second] = SEA;

    for (; !q.empty(); q.pop(), ret++) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;

        for (int d = UP; d <= RIGHT; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (grid[adj_row][adj_col] == LAND) {
                q.push({adj_row, adj_col});
                grid[adj_row][adj_col] = SEA;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos start;
    vector<string> grid;

    start = input(grid);
    cout<<simulate(start, grid)<<'\n';

    return 0;
}