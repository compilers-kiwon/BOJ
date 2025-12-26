#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (1000000)

typedef long long int int64;

void get_prime_numbers(vector<int64>& p) {
    vector<bool> is_prime(MAX_NUM + 1, true);

    for (int i = 2; i <= MAX_NUM; i++) {
        if (is_prime[i] == false) {
            continue;
        }
        
        p.push_back(i);

        for (int j = i + i; j <= MAX_NUM; j += i) {
            is_prime[j] = false;
        }
    }
}

bool is_good_key(int64 key, const vector<int64>& prime_nums) {
    for (int i = 0; i < prime_nums.size(); i++) {
        if (key % prime_nums[i] == 0LL) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int64> p;

    for (cin >> N, get_prime_numbers(p); N > 0; N--) {
        int64 S;
        cin >> S;
        cout << (is_good_key(S, p)?"YES":"NO") << '\n';
    }

    return 0;
}