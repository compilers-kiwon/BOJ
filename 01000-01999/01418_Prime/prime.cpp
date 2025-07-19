#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_prime_numbers(int upper, vector<int>& p) {
    vector<bool> visited(upper + 1, false);

    for (int i = 2; i <= upper; i++) {
        if (visited[i] == true) {
            continue;
        }

        p.push_back(i);

        for (int j = i; j <= upper; j += i) {
            visited[j] = true;
        }
    }
}

int simulate(int upper, int max_prime,
                const vector<int>& prime_numbers) {
    vector<bool> visited(upper + 1, false);
    auto it = upper_bound(prime_numbers.begin(), prime_numbers.end(), max_prime);

    for (; it < prime_numbers.end(); it++) {
        for (int i = *it; i <= upper; i += *it) {
            visited[i] = true;
        }
    }

    int ret = 0;

    for (int i = 1; i <= upper; i++) {
        ret += (visited[i]==false)?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    vector<int> p;

    cin >> N >> K;
    get_prime_numbers(N, p);
    cout << simulate(N, K, p) << '\n';

    return 0;
}