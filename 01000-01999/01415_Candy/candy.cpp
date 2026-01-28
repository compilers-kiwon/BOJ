#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE (50)
#define MAX_PRICE (MAX_SIZE*10000)

typedef long long int int64;

bool is_prime[MAX_PRICE+1];
int64 dp[2][MAX_PRICE+1];
map<int, int> candy;
vector<int> prime_numbers;
int64 num_of_free_candy;

void input(void) {
    int N;

    for (cin >> N; N > 0; --N) {
        int p;

        cin >> p;
        
        if (p != 0) {
            ++candy[p];
        } else {
            ++num_of_free_candy;
        }
    }
}

void get_prime_numbers(void) {
    fill(is_prime, is_prime + MAX_PRICE + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= MAX_PRICE; ++i) {
        if (is_prime[i] == false) {
            continue;
        }

        prime_numbers.push_back(i);

        for (int j = i + i; j <= MAX_PRICE; j += i) {
            is_prime[j] = false;
        }
    }
}

int64 simulate(void) {
    int cur_ptr = 1;

    for (auto c = candy.begin(); c != candy.end(); ++c, cur_ptr = (cur_ptr + 1) % 2) {
        int price = c->first;
        int num_of_candy = c->second;
        int prev_ptr = (cur_ptr + 1) % 2;

        copy(&dp[prev_ptr][0], &dp[prev_ptr][MAX_PRICE+1], &dp[cur_ptr][0]);
        
        for (int i = 1, cur_price = price; i <= num_of_candy; ++i, cur_price += price) {
            int64 upper = MAX_PRICE - cur_price;

            ++dp[cur_ptr][cur_price];

            for (int prev_price = 0; prev_price <= upper; ++prev_price) {
                if (dp[prev_ptr][prev_price] != 0LL) {
                    dp[cur_ptr][prev_price+cur_price] += dp[prev_ptr][prev_price];
                }
            }
        }
    }

    int64 ret = 0LL;

    for (int i = 0; i < prime_numbers.size(); i++) {
        ret += dp[(cur_ptr+1)%2][prime_numbers[i]];
    }

    return (ret * (num_of_free_candy + 1LL));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_prime_numbers();
    cout << simulate() << '\n';

    return 0;
}