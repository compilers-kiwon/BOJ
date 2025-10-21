#include <iostream>

using namespace std;

#define NONE (0x7FFFFFFF)
#define is_odd(n) ((n)%2!=0)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, min_odd_candy, sum;

    for (cin >> N, min_odd_candy = NONE, sum = 0; N > 0; N--) {
        int a;
        
        cin >> a;
        sum += a;
        
        if (is_odd(a) && a < min_odd_candy) {
            min_odd_candy = a;
        } 
    }

    sum -= (is_odd(sum))?min_odd_candy:0;
    cout << sum << '\n';

    return 0;
}