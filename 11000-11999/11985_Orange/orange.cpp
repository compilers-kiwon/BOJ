#include <iostream>

using namespace std;

#define MAX_NUM_OF_ORANGES (20000+1)
#define MAX_SIZE_OF_BOX (1000+1)

#define TBD (-1LL)
#define INF (1000000000000000000LL)

typedef long long int int64;

int N, M;
int64 K, A[MAX_NUM_OF_ORANGES];
int64 dp[MAX_NUM_OF_ORANGES];
int64 diff[MAX_NUM_OF_ORANGES][MAX_SIZE_OF_BOX];

void get_diff(void) {
    for (int orange = 1; orange <= N; orange++) {
        int64 min_orange, max_orange;

        min_orange = max_orange = A[orange];
        diff[orange][1] = 0LL;

        for (int num_of_orange = 2; num_of_orange <= min(M, N - orange + 1); num_of_orange++) {
            int pos = orange + num_of_orange - 1;

            min_orange = min(min_orange, A[pos]);
            max_orange = max(max_orange, A[pos]);
            
            diff[orange][num_of_orange] = max_orange - min_orange;
        }
    }
}

int64 get_dp(int end) {
    if (end <= 0) {
        return 0LL;
    }

    int64& ret = dp[end];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;

    for (int num_of_oranges = 1; num_of_oranges <= min(M, end); num_of_oranges++) {
        int start = max(1, end - num_of_oranges + 1);
        int64 cur_box_cost = K + ((int64)(end - start + 1) * diff[start][num_of_oranges]);
        ret = min(ret, get_dp(start - 1) + cur_box_cost);
    }

    return ret;
}

void input(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], dp[i] = TBD;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_diff();
    cout << get_dp(N) << '\n';

    return 0;
}