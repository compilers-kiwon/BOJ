#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 n, p, d;

    cin >> n >> p;
    n = (n * 10LL) * p * 55LL;
    d = n % 10000LL;

    cout << (n / 10000LL) << '.' << 
        ((d<10)?"000":(d<100)?"00":(d<1000)?"0":"") << d << '\n';
    
    return 0;
}