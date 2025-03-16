#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

enum {
    A_rate = 0,
    B_rate = 1,
    C_rate = 2,
    NUM_OF_RATES = 3
};

const pair<int,int64_t> rate_table[] = {
    {1, 5}, {3, 20}, {5, 35}
};

typedef pair<int64_t,int> State;

int64_t get_interest(int64_t money, int64_t rate) {
    return (money*rate/100);
}

void calculate_next_money(int64_t cur_money, int today,
                            int end_time, queue<State>& q) {
    for (int i = 0; i < NUM_OF_RATES; i++) {
        int64_t next_money;
        int next_day;

        next_day = today + rate_table[i].first;

        if (next_day > end_time) {
            continue;
        }

        next_money = cur_money +
            get_interest(cur_money, rate_table[i].second);
        q.push({next_money, next_day});
    }
}

int64_t simulate(int64_t principal, int end_time) {
    queue<State> q;
    int64_t ret = principal;

    calculate_next_money(principal, 0, end_time, q);

    for (; !q.empty(); q.pop()) {
        int64_t cur_money = q.front().first;
        int today = q.front().second;

        ret = max(ret, cur_money);
        calculate_next_money(cur_money, today, end_time, q);
    }

    return ret;
}

int main(void) {
    int64_t H;
    int Y;

    cin>>H>>Y;
    cout<<simulate(H, Y)<<'\n';

    return 0;
}