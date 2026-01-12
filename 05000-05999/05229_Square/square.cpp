#include <iostream>

using namespace std;

#define MAX_SIZE (30)

bool grid[MAX_SIZE+1][MAX_SIZE+1];

void input(void) {
    int k;

    for (cin >> k; k > 0; k--) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = true;
    }
}

bool is_sqaure(int row, int col, int size) {
    const struct {
        int d_row, d_col;
    } adj[3] = {{1, 0}, {0, 1}, {1, 1}};

    for (int i = 0; i < 3; i++) {
        int adj_row = row + (adj[i].d_row * size);
        int adj_col = col + (adj[i].d_col * size);

        if (grid[adj_row][adj_col] == false) {
            return false;
        }
    }

    return true;
}

int simulate(int cnt[]) {
    int ret = 0;

    for (int row = 0; row <= MAX_SIZE; row++) {
        for (int col = 0; col <= MAX_SIZE; col++) {
            if (grid[row][col] == false) {
                continue;
            }

            for (int size = min(MAX_SIZE - row, MAX_SIZE - col); size > 0; size--) {
                cnt[size] += is_sqaure(row, col, size)?1:0;
            }
        }
    }

    return ret;
}

int get_size_of_max_cnt(int cnt[]) {
    int ret = 0;

    for (int i = MAX_SIZE; i > 0; i--) {
        if (cnt[i] > cnt[ret]) {
            ret = i;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int cnt[MAX_SIZE+1], num_of_sqaures;

        fill(cnt, cnt + (MAX_SIZE + 1), 0);
        fill(&grid[0][0], &grid[0][0] + ((MAX_SIZE + 1) * (MAX_SIZE + 1)), false);
        
        input();
        num_of_sqaures = simulate(cnt);

        int n = get_size_of_max_cnt(cnt);

        if (n == 0) {
            cout << "No squares among the points.\n";
        } else {
            cout << "LENGTH = " << n <<
                    ", COUNT = " << cnt[n] << '\n';
        }
    }

    return 0;
}