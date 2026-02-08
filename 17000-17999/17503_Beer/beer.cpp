#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> Beer; // <preference, alchol>

#define MAX_SIZE (200000+1)
#define MAX_ALCHOL (0x80000000LL)

Beer b[MAX_SIZE];

#define preference first
#define alchol second

bool is_better(const Beer& b1, const Beer& b2) {
    if (b1.first != b2.first) {
        return (b1.first > b2.first);
    }

    return (b1.second < b2.second);
}

void input(int64& N, int64& M, int64& K) {
    cin >> N >> M >> K;

    for (int64 i = 1; i <= K; ++i) {
        cin >> b[i].preference >> b[i].alchol;
    }

    sort(&b[1], &b[K+1], is_better);
}

bool simulate(int64 allowed, int64 target_preference,
                int64 num_of_days, int64 num_of_beers) {
    for (int64 day = 1LL, beer_ptr = 1LL;
            day <= num_of_days && beer_ptr <= num_of_beers; ++day) {
        for (; beer_ptr <= num_of_beers &&
                b[beer_ptr].alchol > allowed; ++beer_ptr) {}

        if (beer_ptr > num_of_beers) {
            continue;
        }
        
        if ((target_preference -= b[beer_ptr++].preference) <= 0LL) {
            if (day == num_of_days) {
                return true;
            }

            continue;
        }
    }

    return false;
}

int64 bin_search(int64 lo, int64 hi, int64 num_of_days,
                    int64 num_of_beers, int64 target_preference) {
    int64 ret = -1LL;

    for (; lo <= hi;) {
        int64 mid = (lo + hi) / 2LL;

        if (simulate(mid, target_preference,
                        num_of_days, num_of_beers) == true) {
            ret = mid, hi = mid - 1LL;
        } else {
            lo = mid + 1LL;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, M, K;

    input(N, M, K);
    cout << bin_search(1LL, MAX_ALCHOL, N, K, M) << '\n';

    return 0;
}