#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX_DIR (4)
#define MAX_SIZE (500+1)

typedef pair<int, int> Pos;

typedef struct {
    int color, size, idx;
    vector<Pos> v;
    vector<int> connected;
} Block;

int H, W;
int color_grid[MAX_SIZE][MAX_SIZE];
int block_grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
vector<Block> graph;

const struct {
    int d_row, d_col;
} adj[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(void) {
    cin >> H >> W;

    for (int row = 1; row <= H; row++) {
        for (int col = 1; col <= W; col++) {
            cin >> color_grid[row][col];
        }
    }
}

void dfs(int cur_row, int cur_col, Block& b, int c, int b_idx) {
    b.v.push_back({cur_row, cur_col});
    block_grid[cur_row][cur_col] = b_idx;

    for (int d = 0; d < MAX_DIR; d++) {
        int adj_row = cur_row + adj[d].d_row;
        int adj_col = cur_col + adj[d].d_col;

        if (!IN_RANGE(1, adj_row, H) || !IN_RANGE(1, adj_col, W)) {
            continue;
        }

        if (visited[adj_row][adj_col] == true ||
                color_grid[adj_row][adj_col] != c) {
            continue;
        }

        visited[adj_row][adj_col] = true;
        dfs(adj_row, adj_col, b, c, b_idx);
    }
}

void get_blocks(void) {
    int idx = 0;

    for (int row = 1; row <= H; row++) {
        for (int col = 1; col <= W; col++) {
            if (visited[row][col] == false) {
                Block b;

                visited[row][col] = true;
                dfs(row, col, b, color_grid[row][col], idx);

                b.color = color_grid[row][col];
                b.size = b.v.size(), b.idx = idx;
                
                graph.push_back(b);
                idx++;
            }
        }
    }
}

void get_adj_blocks(int cur, vector<Pos>& p, vector<int>& adj_blocks) {
    unordered_set<int> used;

    for (auto it = p.begin(); it != p.end(); it++) {
        int cur_row = it->first;
        int cur_col = it->second;

        for (int d = 0; d < MAX_DIR; d++) {
            int adj_row = cur_row + adj[d].d_row;
            int adj_col = cur_col + adj[d].d_col;

            if (!IN_RANGE(1, adj_row, H) || !IN_RANGE(1, adj_col, W)) {
                continue;
            }

            int adj_block_idx = block_grid[adj_row][adj_col];

            if(adj_block_idx != cur &&
                    used.find(adj_block_idx) == used.end()) {
                used.insert(adj_block_idx);
                adj_blocks.push_back(adj_block_idx);
            }
        }
    }
}

void build_graph(void) {
    for (int i = 0; i < graph.size(); i++) {
        vector<int>& adj = graph[i].connected;
        get_adj_blocks(i, graph[i].v, adj);
    }
}

int get_max_adj_color(const vector<int>& connected) {
    int ret = 0;
    unordered_map<int, int> size_of_colors;

    for (auto it = connected.begin(); it != connected.end(); it++) {
        int adj_color = graph[*it].color;
        size_of_colors[adj_color] += graph[*it].size;
        ret = max(ret, size_of_colors[adj_color]);
    }

    return ret;
}

int simulate(void) {
    int ret = 0;

    for (int i = 0; i < graph.size(); i++) {
        ret = max(ret,
            graph[i].size + get_max_adj_color(graph[i].connected));
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_blocks();
    build_graph();
    
    cout << simulate() << '\n';

    return 0;
}