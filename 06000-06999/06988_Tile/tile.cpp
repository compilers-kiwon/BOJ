#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (3000+1)
#define MAX_NUM (1000000+1)

typedef long long int int64;

int N, t[MAX_SIZE];
bool used[MAX_NUM];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        used[t[i]] = true;
    }
}

int64 simulate(void) {
    int64 ret = 0;

    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            int cnt = 1;
            int64 sum = t[i];
            int offset = t[j] - t[i];

            for (;;++cnt) {
                int expected = t[i] + (cnt * offset);

                if (expected > t[N] || used[expected] == false) {
                    break;
                }

                sum += (int64)expected;
            }

            if (cnt >= 3) {
                ret = max(ret, sum);
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