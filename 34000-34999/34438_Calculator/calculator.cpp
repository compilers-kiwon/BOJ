#include <iostream>
#include <vector>

using namespace std;

#define NUM_OF_PLAYERS (3)

int input(vector<int>& days) {
    int n;

    for (int i = 1; i <= NUM_OF_PLAYERS; i++) {
        int d;
        cin >> d;
        days.push_back(d);
    }

    cin >> n;
    return n;
}

int get_gcd(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);
    int mod = big % small;

    for (; mod != 0; mod = big % small) {
        big = small;
        small = mod;
    }

    return small;
}

int get_lcm(const vector<int>& days) {
    int gcd, lcm;

    lcm = 1;

    for (int i = 0; i < days.size(); i++) {
        gcd = get_gcd(days[i], lcm);
        lcm *= days[i] / gcd;
    }

    return lcm;
}

bool is_available(int d, const vector<int>& days) {
    for (int i = 0; i < days.size(); i++) {
        if ((d % days[i]) == 0) {
            return false;
        }
    }

    return true;
}

int count_available(const vector<int>& days, int size) {
    int ret = 0;

    for (int i = 1; i <= size; i++) {
        ret += is_available(i, days)?1:0;
    }

    return ret;
}

int count_available(const vector<int>& days, int size, int target) {
    if (target == 0) {
        return 0;
    }

    int ret, cnt;

    cnt = 0;

    for (int i = 1; i <= size; i++) {
       if (is_available(i, days)) {
           if (++cnt == target) {
               ret = i;
               break;
           }
       }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, period;
    vector<int> d;

    n = input(d);
    period = get_lcm(d);

    int days_to_play, num_of_plays;
    int available_per_period = count_available(d, period);
    
    if ((n % available_per_period) == 0) {
        days_to_play = ((n / available_per_period) - 1) * period;
        num_of_plays = ((n / available_per_period) - 1) * available_per_period;
    } else {
        days_to_play = (n / available_per_period) * period;
        num_of_plays = (n / available_per_period) * available_per_period;
    }
    
    days_to_play += count_available(d, period, n - num_of_plays);

    cout << days_to_play << '\n';    
    return 0;
}