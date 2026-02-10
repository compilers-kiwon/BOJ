#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (100000000)

bool is_prime[MAX_NUM+1];
vector<int> prime_numbers;

void mark_prime_numbers(void) {
    fill(is_prime, is_prime + MAX_NUM + 1, true);

    for (int n = 2; n * n <= MAX_NUM; ++n) {
        if (is_prime[n] == false) {
            continue;
        }

        prime_numbers.push_back(n);

        for (int m = n * n; m <= MAX_NUM; m += n) {
            is_prime[m] = false;
        }
    }
}

pair<int, int> get_prime_numbers(int num) {
    pair<int, int> ret;

    for (int i = 0; i < prime_numbers.size(); ++i) {
        int p1 = prime_numbers[i];
        int p2 = num - p1;

        if (is_prime[p2]) {
            ret = {p1, p2};
            break;
        }
    }

    return ret;
}

void solve(int num) {
    if (num < 8) {
        cout << "Impossible.\n";
        return;
    }

    pair<int, int> p;

    if (num % 2 == 0) {
        cout << "2 2 ";
        p = get_prime_numbers(num - 4);
    } else {
        cout << "2 3 ";
        p = get_prime_numbers(num - 5);
    }

    cout << p.first << ' ' << p.second << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    mark_prime_numbers();

    for (int n; cin >> n;) {
        solve(n);
    }

    return 0;
} 