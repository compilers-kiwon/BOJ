#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if ((num % i) == 0) {
            return false;
        }
    }

    return true;
}

int get_sum_of_digits(int num) {
    int ret = 0;

    for (; num > 0; num /= 10) {
        ret += num % 10;
    }

    return ret;
}

bool is_additive_prime(int num) {
    return is_prime(get_sum_of_digits(num));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    if (is_prime(n)) {
        if (is_additive_prime(n)) {
            cout << "ADDITIVE PRIME\n";
        } else {
            cout << "PRIME, BUT NOT ADDITIVE\n";
        }
    } else {
        cout << "COMPOSITE\n";
    }

    return 0;
}