#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt[3+1];

    cin >> N, fill(cnt, cnt + (3 + 1), 0);

    for (int i = 1; i <= 3 * N; i++) {
        int n;
        cin >> n;
        cnt[n]++;
    }

    int big, small;

    for (int i = 1; i <= 3; i++) {
        if (cnt[i] > N) {
            big = i;
        }

        if (cnt [i] < N) {
            small = i;
        }
    }

    cout << small << '\n' << big << '\n';

    return 0;
}