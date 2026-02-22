#include <iostream>
#include <set>

using namespace std;

#define MAX_SIZE (50+1)

int input(int price[], int cost[], set<int>& p) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> price[i] >> cost[i];
        p.insert(price[i]);
    }

    return N;
}

int simulate(int num_of_customers, int cur_price,
                int price[], int cost[]) {
    int ret = 0;

    for (int i = 1; i <= num_of_customers; ++i) {
        if (cur_price > price[i]) {
            continue;
        }

        ret += max(cur_price - cost[i], 0);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, price[MAX_SIZE], cost[MAX_SIZE];
    int max_profit, ans;
    set<int> used_price;

    N = input(price, cost, used_price), max_profit = 0;

    for (auto it = used_price.begin(); it != used_price.end(); ++it) {
        int cur_profit = simulate(N, *it, price, cost);

        if (cur_profit > max_profit) {
            max_profit = cur_profit, ans = *it;
        }
    }

    cout << (max_profit==0?0:ans) << '\n';

    return 0;
}