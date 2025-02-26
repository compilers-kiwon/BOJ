#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64_t n, k, T, uncomfortable;

    cin>>n>>k>>T;
    uncomfortable = 0;

    for (int64_t i = 1; i <= n; i++) {
        int64_t d;

        cin>>d;
        
        if (T < k) {
            T = T + d + abs(T - k);
        } else if (T > k) {
            T = T + d - abs(T - k);
        } else {
            T = T + d;
        }

        uncomfortable += abs(T - k);
    }

    cout<<uncomfortable<<'\n';

    return 0;
}