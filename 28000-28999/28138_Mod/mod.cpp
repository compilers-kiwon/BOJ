#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int int64;

void get_divisors(int64 num, vector<int64>& d) {
    int64 root = static_cast<int64>(sqrt(num));

    for (int64 i = 1; i <= root; i++) {
        if ((num % i) == 0) {
            d.push_back(i);
            d.push_back(num / i);
        }
    }

    if ((root * root) == num) {
        d.pop_back();
    }
}

int64 get_sum(const vector<int64>& d, int64 r) {
    int64 ret = 0;

    for (int i = 0; i < d.size(); i++) {
        if (d[i] > r) {
            ret += d[i];
        }
    }

    return ret; 
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, R;
    vector<int64> divs;

    cin >> N >> R;
    get_divisors(N - R, divs);
    cout << get_sum(divs, R) << '\n';

    return 0;
}