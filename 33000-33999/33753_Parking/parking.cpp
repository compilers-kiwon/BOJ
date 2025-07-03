#include <iostream>

using namespace std;

int get(int parking_time, int basic_cost, int extra_time, int extra_cost) {
    int ret;

    ret = basic_cost;
    parking_time -= 30;

    if (parking_time > 0) {
        ret += (parking_time / extra_time) * extra_cost;
        ret += ((parking_time % extra_time) == 0)?0:extra_cost;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C, T;

    cin>>A>>B>>C>>T;
    cout<<get(T, A, B, C)<<'\n';

    return 0;
}