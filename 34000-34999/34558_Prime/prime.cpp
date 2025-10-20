#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NONE (-1)
#define MAX_NUM (1000000)

int N;
bool is_prime[MAX_NUM+1];
vector<int> prime_numbers;

void get_prime_numbers(void) {
    fill(is_prime, is_prime + MAX_NUM + 1, true);

    for (int i = 2; i <= MAX_NUM; i++) {
        if (is_prime[i] == false) {
            continue;
        }

        prime_numbers.push_back(i);

        for (int j = i + i; j <= MAX_NUM; j += i) {
            is_prime[j] = false;
        }
    }
}

int get_prime_median(int lo, int hi) {
    auto lower = lower_bound(prime_numbers.begin(), prime_numbers.end(), lo);
    auto upper = upper_bound(prime_numbers.begin(), prime_numbers.end(), hi);

    int lower_idx = lower - prime_numbers.begin();
    int upper_idx = upper - prime_numbers.begin();

    if ((lower_idx + upper_idx) % 2 == 0) {
        return NONE;
    }

    return prime_numbers[(lower_idx+upper_idx)/2];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    get_prime_numbers();

    for (cin >> N; N > 0; N--) {
        int a, b;
        cin >> a >> b;
        cout << get_prime_median(a, b) << '\n';
    }

    return 0;
}