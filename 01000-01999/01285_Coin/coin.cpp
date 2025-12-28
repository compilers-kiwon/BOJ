#include <iostream>

using namespace std;

#define MAX_SIZE (20+1)
#define INF (MAX_SIZE*MAX_SIZE)

int N, grid[MAX_SIZE][MAX_SIZE];

#define FRONT (1)
#define BACK (0)

void reverse_coins(int row) {
    for (int col = 1; col <= N; col++) {
        grid[row][col] = (grid[row][col] + 1) % 2;
    }
}

int get_num_of_back(void) {
    int ret = 0;

    for (int col = 1; col <= N; col++) {
        int num_of_front = 0;
        int num_of_back = 0;

        for (int row = 1; row <= N; row++) {
            (grid[row][col]==1)?num_of_front++:num_of_back++;
        }

        ret += min(num_of_front, num_of_back);
    }

    return ret;
}

void dfs(int row, int& min_num_of_back) {
    if (row > N) {
        min_num_of_back = min(min_num_of_back, get_num_of_back());
        return;
    }

    reverse_coins(row);
    dfs(row + 1, min_num_of_back);
    reverse_coins(row);

    dfs(row + 1, min_num_of_back);
}

void input(void) {
    cin >> N;

    for (int row = 1; row <= N; row++) {
        char buf[MAX_SIZE+1];

        cin >> &buf[1];

        for (int col = 1; col <= N; col++) {
            grid[row][col] = (buf[col]=='H')?FRONT:BACK;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_num_of_back = INF;
    
    input();
    dfs(1, min_num_of_back);
    cout << min_num_of_back << '\n';

    return 0;
}