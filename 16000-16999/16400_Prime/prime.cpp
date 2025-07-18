#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (40000)
#define MOD(n) ((n)%123456789)

vector<int> prime_numbers;
int dp[MAX_NUM+1] = {1, };
bool visited[MAX_NUM+1];

void get_prime_numbers(int upper) {
    for (int i = 2; i <= upper; i++) {
        if (visited[i] == true) {
            continue;
        }

        visited[i] = true;
        prime_numbers.push_back(i);

        for (int j = i + i; j <= upper; j += i) {
            visited[j] = true;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;
    get_prime_numbers(N);

    for (int i = 0; i < prime_numbers.size(); i++) {
        for (int p = prime_numbers[i]; p <= N; p++) {
            dp[p] = MOD(dp[p] + dp[p-prime_numbers[i]]);
        }
    }

    cout << dp[N] << '\n';

    return 0;    
}