#include <iostream>
#include <cmath>

using namespace std;

#define MAX_NUM (1000)
#define NUM_OF_DIVISORS_FOR_RSA (4)

int sum_of_rsa_cnt[MAX_NUM];

int get_num_of_divisors(int n) {
    int ret = 0;
    int s = sqrt(n);

    for (int i = 1; i <= s; i++) {
        if ((n % i) == 0) {
            ret += 2;
        }
    }

    return (ret - ((s*s==n)?1:0));
}

bool is_rsa_num(int n) {
    return (get_num_of_divisors(n) == NUM_OF_DIVISORS_FOR_RSA);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i = 1; i < MAX_NUM; i++) {
        sum_of_rsa_cnt[i] = sum_of_rsa_cnt[i-1] + (is_rsa_num(i)?1:0);
    }

    int a, b;
    cin >> a >> b;
    cout << "The number of RSA numbers between " << a << " and "
            << b << " is " << sum_of_rsa_cnt[b] - sum_of_rsa_cnt[a-1] << '\n';
    
    return 0;
}