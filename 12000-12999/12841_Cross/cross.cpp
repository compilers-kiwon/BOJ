#include <iostream>

using namespace std;

#define MAX_SIZE (100000)
#define INF (1000000LL*1000000LL*1000000LL)
typedef long long int int64;

int64 cross[MAX_SIZE], lpos[MAX_SIZE], rpos[MAX_SIZE];

int input(void) {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cross[i];
    }

    for (int i = 1; i < n; i++) {
        int64 len;
        cin >> len;
        lpos[i] = lpos[i-1] + len;
    }

    for (int i = 1; i < n; i++) {
        int64 len;
        cin >> len;
        rpos[i] = rpos[i-1] + len;
    }

    return n;
}

pair<int, int64> simulate(int num_of_pos) {
    int idx;
    int64 min_len = INF;
    int64 start = lpos[0];
    int64 end = rpos[num_of_pos-1];

    for (int i = 0; i < num_of_pos; i++) {
        int64 left_len = lpos[i] - start;
        int64 right_len = end - rpos[i];
        int64 total_len = left_len + right_len + cross[i];

        if (total_len < min_len) {
            idx = i, min_len = total_len;
        }
    }

    return {idx, min_len};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n = input();
    pair<int, int64> ans = simulate(n);
    cout << ans.first + 1 << ' ' << ans.second << '\n';

    return 0;
}