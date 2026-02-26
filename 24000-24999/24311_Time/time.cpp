#include <iostream>
#include <iomanip>

using namespace std;

int get_minutes(int h, int m) {
    return (h * 60) + m;
}

void print_depature_time(int arrival_time, int required_time) {
    int t = arrival_time - required_time;
    int h = t / 60;
    int m = t % 60;

    cout << setw(2) << setfill('0') << h << ' '
            << setw(2) << setfill('0') << m << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t1, t2;
    int t3;
    int t4, t5;
    int br;
    int t6;

    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> br >> t6;

    int required_time = get_minutes(t4, t5) + t3 + ((br + 1) * t6);
    int start_time = get_minutes(t1, t2);
    
    print_depature_time(start_time - 10, required_time);
    return 0;
}