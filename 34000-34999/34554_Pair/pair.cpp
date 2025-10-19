#include <iostream>

using namespace std;

#define MAX_NUM (10000+1)

bool is_prime[MAX_NUM+1];

void get_prime_numbers(void) {
    fill(is_prime, is_prime + MAX_NUM + 1, true);

    for (int i = 2; i <= MAX_NUM; i++) {
        if (is_prime[i] == true) {
            for (int j = i + i; j <= MAX_NUM; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin >> T;
    get_prime_numbers();

    for (int t = 1; t <= T; t++) {
        int N;

        cin >> N;

        if (is_prime[N+1] == true) {
            cout << "1\n" << "1 " << 1 + N << '\n';
        } else {
            cout << "0\n";
        }
    }

    return 0;
}