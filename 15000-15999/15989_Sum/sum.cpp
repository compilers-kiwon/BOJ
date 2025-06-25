#include <iostream>

#define MAX_NUM (10000)

int dp[MAX_NUM+1];

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    dp[0] = 1;

    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= MAX_NUM; j++) {
            dp[j] += dp[j - i];
        }
    }

    int T;

    std::cin>>T;

    for (int t = 1; t <= T; t++) {
        int n;
        std::cin>>n;
        std::cout<<dp[n]<<'\n';
    }

    return 0;
}