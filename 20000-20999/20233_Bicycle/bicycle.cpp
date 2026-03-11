#include <iostream>

using namespace std;

const int num_of_working_days = 21;
const int a_free_usage_time = 30;
const int b_free_usage_time = 45;

int get_daily_cost(int total_time, int free_time, int per_minute_fee) {
    return (max(0, total_time - free_time) * per_minute_fee);
}

int get_total_cost(int total_time, int free_time, int base_fee, int per_minute_fee) {
    return base_fee + get_daily_cost(total_time, free_time, per_minute_fee) * num_of_working_days;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, x, b, y, T;
    cin >> a >> x >> b >> y >> T;
    cout << get_total_cost(T, a_free_usage_time, a, x) << ' '
            << get_total_cost(T, b_free_usage_time, b, y) << '\n';
    
    return 0;
}