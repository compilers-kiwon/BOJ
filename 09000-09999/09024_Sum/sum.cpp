#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF (1000000000)
#define MAX_SIZE (1000000+1)

int N, K, n[MAX_SIZE];

void input(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> n [i];
    }

    sort(&n[1], &n[N+1]);
}

int simulate(void) {
    int min_diff, cnt;

    min_diff = INF, cnt = 0;

    for (int h = 1, t = N; h < t;) {
        int sum = n[h] + n[t];
        int diff = abs(K - sum);

        if (diff <= min_diff) {
            if (diff < min_diff) {
                min_diff = diff, cnt = 0;
            }

            cnt++;
        }

        h += (sum<=K)?1:0, t -= (sum>=K)?1:0;
    }

    return cnt;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; T--) {
        input();
        cout << simulate() << '\n';
    }

    return 0;
}