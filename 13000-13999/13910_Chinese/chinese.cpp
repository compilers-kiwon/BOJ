#include <iostream>

#define MAX_NUM_OF_WOKS (100+1)
#define MAX_NUM_OF_ORDERS (10000+1)

#define TBD (-1)
#define INF (0x7FFFFFFF)

int N, M, S[MAX_NUM_OF_WOKS], dp[MAX_NUM_OF_ORDERS];

void input(void) {
    std::cin>>N>>M;

    for (int i = 1; i <= M; i++) {
        std::cin>>S[i];
    }

    std::fill(&dp[1], &dp[N+1], TBD);
}

int get_dp(int num_of_orders) {
    if (num_of_orders < 0) {
        return INF;
    }

    if (num_of_orders == 0) {
        return 0;
    }

    int d;
    int& ret = dp[num_of_orders];

    if (ret != TBD) {
        return ret;
    }

    ret = INF;

    for (int i = 1; i <= M; i++) {
        d = get_dp(num_of_orders - S[i]);

        if (d != INF) {
            ret = std::min(ret, d + 1);
        }

        for (int j = i + 1; j <= M; j++) {
            d = get_dp(num_of_orders - S[i] - S[j]);

            if (d != INF) {
                ret = std::min(ret, d + 1);
            }
        }
    }

    return ret;
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int result;

    input();
    result = get_dp(N);
    std::cout<<((result==INF)?-1:result)<<'\n';

    return 0;
}