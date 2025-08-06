#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (3000+1)

int N, A[MAX_SIZE], diff_from_prev[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(&A[1], &A[N+1]);
}

void get_diffs(void) {
    diff_from_prev[1] = 0;

    for (int i = 2; i <= N; i++) {
        diff_from_prev[i] = A[i] - A[i-1];
    }
}

int simulate(void) {
    int ret = -1;
    int max_diff = 0;

    for (int i = 2; i <= N; i++) {
        if (diff_from_prev[i] == 1) {
           continue;
        }

        int cur_pos = (A[i] + A[i-1]) / 2;
        int cur_diff = min(A[i] - cur_pos, cur_pos - A[i-1]);

        if (cur_diff > max_diff) {
            ret = cur_pos;
            max_diff = cur_diff;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_diffs();
    cout << simulate() << '\n';

    return 0;
}