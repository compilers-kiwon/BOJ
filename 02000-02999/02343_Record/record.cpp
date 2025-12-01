#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (100000+1)
#define MAX_LEN (10000*MAX_SIZE)
#define NONE (0x7FFFFFFF)

int N, M, L[MAX_SIZE];

int simulate(int max_length) {
    vector<int> r = {0};

    for (int i = 1; i <= N; i++) {
        if (L[i] > max_length) {
            return NONE;
        }

        if (r.back() + L[i] <= max_length) {
            r.back() += L[i];
        } else {
            r.push_back(L[i]);
        }

        if (r.size() > M) {
            return NONE;
        }
    }
    
    return (int)r.size();
}

int bin_search(int lower) {
    int lo, hi, ret;

    for (lo = lower, hi = MAX_LEN, ret = MAX_LEN; lo <= hi;) {
        int mid = (lo + hi) / 2;
        int num_of_records = simulate(mid);

        if (num_of_records <= M) {
            ret = min(ret, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

int input(void) {
    int min_required = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> L[i];
        min_required = max(min_required, L[i]);
    }

    return min_required;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int lower = input();
    cout << bin_search(lower) << '\n';

    return 0;
}