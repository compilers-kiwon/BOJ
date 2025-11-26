#include <iostream>

using namespace std;

typedef long long int int64;

#define MAX_SIZE (100000+1)

int N;
int64 W, sum[MAX_SIZE];

void input(void) {
    cin >> W >> N;

    for (int i = 1; i <= N; i++) {
        int64 w;
        cin >> w;
        sum[i] = sum[i-1] + w;
    }
}

int simulate(void) {
    int ret = 0;

    for (int i = 1; i <= 3; i++) {
        if (sum[i] > W) {
            break;
        }

        ret = i;
    }

    for (int h = 1; h <= N; h++) {
        int64 w = sum[min(h+3, N)] - sum[h-1];

        if (w > W) {
            break;
        }

        ret = min(h+3, N);
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