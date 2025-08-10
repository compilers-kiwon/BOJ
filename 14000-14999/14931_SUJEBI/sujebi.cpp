#include <iostream>

using namespace std;

#define MAX_SIZE (1000000+1)

typedef long long int int64;

int L, score[MAX_SIZE];
int64 sum[MAX_SIZE];

void input(void) {
    cin >> L;

    for (int i = 1; i <= L; i++) {
        cin >> score[i];
    }
}

void get_sum(int offset) {
    int64& result = sum[offset];

    for (int i = offset; i <= L; i += offset) {
        result += (int64)score[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int d = 1; d <= L; d++) {
        get_sum(d);
    }

    int max_pos = 0;

    for (int i = 1; i <= L; i++) {
        if (sum[i] > sum[max_pos]) {
            max_pos = i;
        }
    }

    cout << max_pos << ' ' << sum[max_pos] << '\n';

    return 0;
}