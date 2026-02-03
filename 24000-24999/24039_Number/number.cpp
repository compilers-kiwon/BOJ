#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_NUM = 10000;

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void get_special_numbers(vector<int>& numbers) {
    int prev_prime_number;
    vector<int> prime_numbers;

    for (int i = 2;; ++i) {
        if (is_prime(i) == true) {
            prev_prime_number = (prime_numbers.empty())?0:prime_numbers.back();
            prime_numbers.push_back(i);

            if (prev_prime_number * i > MAX_NUM) {
                break;
            }
        }
    }

    for (int i = 0; i < prime_numbers.size() - 1; ++i) {
        numbers.push_back(prime_numbers[i] * prime_numbers[i+1]);
    }
}

int simulate(int n, const vector<int>& numbers) {
    return *(upper_bound(numbers.begin(), numbers.end(), n));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> special_numbers;

    cin >> N, get_special_numbers(special_numbers);
    cout << simulate(N, special_numbers) << '\n';

    return 0;
}