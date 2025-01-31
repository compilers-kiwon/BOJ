#include <iostream>
#include <cstdint>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int64_t N, A, Pa, B, Pb;

    cin>>N>>A>>Pa>>B>>Pb;

    int64_t cheap_cost, cheap_power;
    int64_t expensive_cost, expensive_power;

    if (Pa < Pb) {
        cheap_cost = Pa, cheap_power = A;
        expensive_cost = Pb, expensive_power = B;
    } else {
        cheap_cost = Pb, cheap_power = B;
        expensive_cost = Pa, expensive_power = A;
    }

    int64_t max_power = 0;
    int64_t max_num_of_cheap_soldiers = 0;
    int64_t max_num_of_expensive_soldiers = 0;

    for (int64_t num_of_cheap_soldiers = N/cheap_cost;
            num_of_cheap_soldiers >= 0; num_of_cheap_soldiers--) {
        int64_t total_cheap_cost = num_of_cheap_soldiers * cheap_cost;
        int64_t total_expensive_cost = N - total_cheap_cost;
        int64_t num_of_expensive_soldiers = total_expensive_cost / expensive_cost;
        int64_t cur_power = (num_of_cheap_soldiers * cheap_power) +
                                (num_of_expensive_soldiers * expensive_power);
        
        if (cur_power > max_power) {
            max_power = cur_power;
            max_num_of_cheap_soldiers = num_of_cheap_soldiers;
            max_num_of_expensive_soldiers = num_of_expensive_soldiers;
        }
    }

    if (cheap_power == A) { // cheap: tanker, expensive: dealer
        cout<<max_num_of_cheap_soldiers<<' '<<max_num_of_expensive_soldiers<<'\n';
    } else {
        cout<<max_num_of_expensive_soldiers<<' '<<max_num_of_cheap_soldiers<<'\n';
    }

    return 0;
}