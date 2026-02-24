#include <iostream>

using namespace std;

#define MAX_SIZE (200000+1)

int N, K, X, sum[MAX_SIZE];

bool simulate(int num_of_holidays) {
    for (int s = 1; s <= N - num_of_holidays + 1; ++s) {
        int end_day_of_first_working = s - 1;
        int start_day_of_second_working = s + num_of_holidays;

        int first_income = sum[end_day_of_first_working] * X;
        int second_income = sum[N] - sum[start_day_of_second_working-1];

        if ((first_income + second_income) >= K) {
            return true;
        }
    }

    return false;
}

int bin_search(int lo, int hi) {
    int ret = -1;

    for (; lo <= hi;) {
        int mid =(lo + hi) / 2;

        if (simulate(mid) == true) {
            ret = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> K >> X;

    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << bin_search(1, N - 1) << '\n';

    return 0;
}