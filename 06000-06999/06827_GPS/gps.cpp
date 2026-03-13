#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Pos; // <row, col>

const int ROW_SIZE = 5;
const int COL_SIZE = 6;

void init(unordered_map<char, Pos>& g) {
    char c = 'A';

    for (int row = 0; row < ROW_SIZE && c <= 'Z'; ++row) {
        for (int col = 0; col < COL_SIZE && c <= 'Z'; ++ col) {
            g[c++] = {row, col};
        }
    }

    g[' '] = {4, 2}, g['-'] = {4, 3}, g['.'] = {4, 4}, g['\n'] = {4, 5}; 
}

int simulate(const string& s, unordered_map<char, Pos>& g) {
    int ret = 0;
    Pos prev_pos = {0, 0};

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        Pos cur_pos = g[c];

        ret += abs(prev_pos.first - cur_pos.first)
                + abs(prev_pos.second - cur_pos.second);

        prev_pos = cur_pos;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    unordered_map<char, Pos> grid;

    init(grid);
    getline(cin, s);

    s.push_back('\n');
    cout << simulate(s, grid) << '\n';
    
    return 0;
}