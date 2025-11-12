#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE (10000)

typedef long long int int64;

int N;
int64 T, temperature[MAX_SIZE];

int64 get_noise_level(int group_size) {
    int num_of_groups = N / group_size;

    if (num_of_groups == 1) {
        return 0LL;
    }
    
    int64 max_diff, prev_avg;

    max_diff = 0LL, prev_avg = -1LL;

    for (int i = 0; i < num_of_groups; i++) {
        int64 sum = 0;

        for (int j = 0; j < group_size; j++) {
            sum += temperature[(i*group_size)+j];
        }

        int64 avg = sum / (int64)group_size;

        if (prev_avg >= 0) {
            max_diff = max(max_diff, abs(prev_avg - avg));
        }

        prev_avg = avg;
    }

    return max_diff;
}

void input(void) {
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> temperature[i];
    }
}

int simulate(void) {
    int ret;

    for (int i = 1; i <= (N / 2) + 1; i++) {
        if (get_noise_level(i) <= T) {
            ret = i;
            break;
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