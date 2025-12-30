#include <iostream>

using namespace std;

#define MAX_SIZE (3000+1)

int N, A[MAX_SIZE], dp[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], dp[i] = MAX_SIZE;
    }
}

int simulate(void) {
    for (int i = 1; i <= N; i++) {
        dp[i] = min(dp[i-1] + 1, dp[i]);

        for (int num_of_inclusive = 1; num_of_inclusive < A[i]; num_of_inclusive++) {
            if (i + num_of_inclusive <= N) {
                dp[i+num_of_inclusive] = min(dp[i-1] + 1, dp[i+num_of_inclusive]);
            }
        }
    }
    
    return dp[N];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}