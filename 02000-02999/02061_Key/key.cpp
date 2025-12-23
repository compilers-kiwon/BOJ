#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

void get_prime_nums(vector<int>& prime_nums, int upper) {
    vector<bool> is_prime(upper, true);

    for (int i = 2; i < upper; i++) {
        if (is_prime[i] == false) {
            continue;
        }

        for (int j = i + i; j < upper; j += i) {
            is_prime[j] = false;
        }

        prime_nums.push_back(i);
    }
}

bool is_good_key(const string& num, int p) {
    int cur = 0;

    for (int i = 0; i < num.length(); i++) {
        cur = ((cur * 10) + chr2int(num[i])) % p;
    }

    return (cur != 0);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L;
    string K;
    vector<int> prime_numbers;

    cin >> K >> L;
    get_prime_nums(prime_numbers, L);

    for (int i = 0; i < prime_numbers.size(); i++) {
        if (is_good_key(K, prime_numbers[i]) == false) {
            cout << "BAD " << prime_numbers[i] << '\n';
            return 0;
        }
    }

    if (K.length() <= to_string(L).length() && stoi(K) < L) {
        cout << "BAD " << K << '\n';
    } else {
        cout << "GOOD\n";
    }

    return 0;
}