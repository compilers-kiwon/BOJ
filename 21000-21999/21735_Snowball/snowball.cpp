#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)

int N, M, a[MAX_SIZE];

int dfs(int cur_pos, int cur_size, int cur_time) {
    if (cur_time == M || cur_pos == N) {
        return cur_size;
    }

    int ret = 0;

    for (int offset = 1; offset <= 2; offset++) {
        int adj_pos = cur_pos + offset;

        if (adj_pos <= N) {
            ret = max(ret, dfs(adj_pos, (cur_size / offset) + a[adj_pos], cur_time + 1));
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << dfs(0, 1, 0) << '\n';

    return 0;
}