#include <iostream>

using namespace std;

#define MAX_SIZE (10000000)
#define MOD(n) ((n)%1000000007)

typedef long long int int64;

int64 dp[MAX_SIZE+1];

void init(void) {
    dp[1] = 4LL;

    for (int d = 2; d <= MAX_SIZE; ++d) {
        dp[d] = MOD(dp[d-1] * 5LL);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;

    for (cin >> Q, init(); Q > 0; --Q) {
        int N;
        cin >> N;
        cout << (N==1?5LL:dp[N]) << '\n';
    }

    return 0;
}