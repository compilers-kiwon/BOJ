#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

// <<-available time, -counter id>, customer id>>
typedef pair<pair<int64_t,int64_t>,int64_t> Counter;

// <customer id, number of items>
typedef pair<int64_t,int64_t> Customer;

int64_t N, k;
queue<Customer> customer_q;
priority_queue<Counter> counter_q;
queue<int64_t> checked_order;

#define get_available_counter_time(pq) (-((pq).top().first.first))
#define get_available_counter_id(pq) (-((pq).top().first.second))
#define get_checked_customer_id(pq) ((pq).top().second)

void input(void) {
    cin>>N>>k;

    for (int64_t i = 1; i <= N; i++) {
        int64_t id, w;

        cin>>id>>w;
        customer_q.push({id, w});
    }

    for (int64_t i = 1; i <= k; i++) {
        counter_q.push({{0, -i}, 0});
    }
}

int64_t simulate(void) {
    priority_queue<pair<int64_t,int64_t>> checked;

    for ( ; checked_order.size() != N; ) {
        for (int64_t cur_time = get_available_counter_time(counter_q);
                !counter_q.empty() && cur_time == get_available_counter_time(counter_q);
                counter_q.pop()) {
            int64_t available_counter_id = get_available_counter_id(counter_q);
            int64_t checked_customer_id = get_checked_customer_id(counter_q);

            checked.push({available_counter_id, checked_customer_id});

            if (!customer_q.empty()) {
                int64_t customer_id = customer_q.front().first;
                int64_t num_of_items = customer_q.front().second;

                customer_q.pop();
                counter_q.push({
                    {-(cur_time + num_of_items), -available_counter_id}, customer_id}
                );
            }
        }

        for ( ; !checked.empty(); checked.pop()) {
            if (checked.top().second != 0) {
                checked_order.push(checked.top().second);
            }
        }
    }

    int64_t ret = 0;

    for (int64_t i = 1; !checked_order.empty(); checked_order.pop(), i++) {
        ret += i * checked_order.front();
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return 0;
}