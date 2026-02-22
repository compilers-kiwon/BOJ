#include <iostream>

using namespace std;

int input(int& N, int& T, int& start_time) {
    int HH1, MM1, HH2, MM2, ret;
    char dummy;

    cin >> HH1 >> dummy >> MM1
            >> HH2 >> dummy >> MM2;
    cin >> N >> T;

    start_time = HH1 * 60 + MM1;
    ret = (HH2 * 60 + MM2) - start_time;
    
    return ret;
}

int simulate(int num_of_items, int delivery_time,
                int start_time, int working_time, int& num_of_days) {
    int num_of_items_per_day = working_time / delivery_time;

    if (working_time % delivery_time == 0) {
        --num_of_items_per_day;
    }

    for (; num_of_items > num_of_items_per_day; ++num_of_days) {
        num_of_items -= num_of_items_per_day;
    }

    return (start_time + num_of_items * delivery_time);
}

void print(int num_of_days, int time) {
    cout << num_of_days << '\n';

    int HH = time / 60;
    int MM = time % 60;

    cout << (HH < 10?"0":"") << HH << ':';
    cout << (MM < 10?"0":"") << MM << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int working_time, start_time;
    int N, T, num_of_days, delivery_time;

    working_time = input(N, T, start_time), num_of_days = 0;
    delivery_time = simulate(N + 1, T, start_time,
                                working_time, num_of_days);
    print(num_of_days, delivery_time);

    return 0;
}