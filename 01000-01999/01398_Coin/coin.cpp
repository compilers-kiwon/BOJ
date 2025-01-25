#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const uint64_t MAX_NUM = 1000000000000000;

map<uint64_t, size_t> dp;
vector<uint64_t> coins_10, coins_25;

void init(void) {
    coins_10.push_back(1);
    coins_25.push_back(1);

    uint64_t cur;

    for (cur = 10; cur <= MAX_NUM; cur *= 10) {
        coins_10.push_back(cur);
    }

    for (cur = 25; cur <= MAX_NUM; cur *= 100) {
        coins_25.push_back(cur);
    }
}

uint64_t find_coin(uint64_t cur, vector<uint64_t>& coins) {
    vector<uint64_t>::iterator it =
        upper_bound(coins.begin(), coins.end(), cur);
    return *(it-1); 
}

size_t get_dp(uint64_t cur) {
    if (cur == 0) {
        return 0;
    }
    
    if (dp.find(cur) != dp.end()) {
        return dp[cur];
    }

    size_t& ret = dp[cur];

    ret = min(get_dp(cur - find_coin(cur, coins_10)) + 1,
                get_dp(cur - find_coin(cur, coins_25)) + 1);
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t T;

    init();
    
    cin>>T;
    dp[1] = 1;

    for (size_t t = 1; t <= T; t++) {
        uint64_t price;

        cin>>price;
        cout<<get_dp(price)<<'\n';
    }

    return 0;
}