#include <iostream>

using namespace std;

#define MAX_DIR (6)
#define MAX_SIZE (100)

int N, M;
bool c[MAX_SIZE+1][MAX_SIZE+1][MAX_SIZE+1];

const struct {
    int dx, dy, dz;
} adj[MAX_DIR] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0},
                    {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void input(void) {
    int z;

    cin >> N >> M;

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= M; ++y) {
            for (cin >> z; z > 0; --z) {
                c[x][y][z] = true;
            }
        }
    }
}

int get_num_of_adj_cubes(int x, int y, int z) {
    int ret = 0;

    for (int d = 0; d < MAX_DIR; ++d) {
        int adj_x = x + adj[d].dx;
        int adj_y = y + adj[d].dy;
        int adj_z = z + adj[d].dz;

        if (!IN_RANGE(1, adj_x, MAX_SIZE) ||
            !IN_RANGE(1, adj_y, MAX_SIZE) ||
            !IN_RANGE(1, adj_z, MAX_SIZE)) {
            continue;
        }

        ret += c[adj_x][adj_y][adj_z]?1:0;
    }

    return ret;
}

int simulate(void) {
    int ret = 0;

    for (int x = 1; x <= MAX_SIZE; ++x) {
        for (int y = 1; y <= MAX_SIZE; ++y) {
            for (int z = 1; z <= MAX_SIZE; ++z) {
                ret += c[x][y][z]?6-get_num_of_adj_cubes(x, y, z):0;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}