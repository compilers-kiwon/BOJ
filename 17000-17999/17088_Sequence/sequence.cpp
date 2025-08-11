#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE (100000+1)

int N, B[MAX_SIZE], ans;

void check_number(int idx, int cnt) {
    if (idx == N + 1) {
        if (ans == -1 || cnt < ans) {
            ans = cnt;
        }
    }

    int offset = B[idx-1] - B[idx-2];

    for (int d = -1; d <= 1; d++) {
        B[idx] += d;

        if ((B[idx] - B[idx-1]) == offset) {
            check_number(idx + 1, cnt + abs(d));
        }

        B[idx] -= d;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;
    ans = -1;

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    if ((N == 1) || (N == 2)) {
        cout << "0\n";
        return 0;
    }

    for (int d1 = -1; d1 <= 1; d1++) {
        B[1] += d1;

        for (int d2 = -1; d2 <= 1; d2++) {
            B[2] += d2;
            check_number(3, abs(d1) + abs(d2));
            B[2] -= d2;
        }
        
        B[1] -= d1;
    }

    cout << ans << '\n';

    return 0;
}