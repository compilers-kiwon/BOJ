#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_NUM (2700)

int get_sum_of_digits(int N) {
    int ret = 0;

    for (; N > 0; N /= 10) {
        ret += N % 10;
    }

    return ret;
}

bool is_type_1(int N) {
    if (N == 5) {
        return false;
    }
    
    return (N >= 4 && get_sum_of_digits(N) % 2 == 1);
}

void prime_factorization(const vector<int>& p, set<int>& used, int num) {
    for (int i = 0; num > 1 && i < p.size(); ++i) {
        for (; num % p[i] == 0; num /= p[i]) {
            used.insert(p[i]);
        }
    }
}

void get_prime_numbers(vector<int>& p) {
    vector<bool> is_prime(MAX_NUM + 1, true);

    for (int i = 2; i <= MAX_NUM; ++i) {
        if (is_prime[i] == false) {
            continue;
        }

        p.push_back(i);

        for (int j = i + i; j <= MAX_NUM; j += i) {
            is_prime[j] = false;
        }
    }
}

bool is_type_2(int N) {
    if (N == 2 || N == 4) {
        return true;
    }

    set<int> used;
    vector<int> prime_numbers;
    
    get_prime_numbers(prime_numbers);
    prime_factorization(prime_numbers, used, N);
    
    return (!used.empty() && (used.size() % 2) == 0);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    bool t1, t2;

    cin >> N;
    t1 = is_type_1(N), t2 = is_type_2(N);

    if (t1 && t2) {
        cout << "4\n";
    } else if (!t1 && !t2) {
        cout << "3\n";
    } else {
        cout << (t1?1:2) << '\n';
    }

    return 0;
}