#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X, cur_sum;

    cin >> N >> X, cur_sum = 0;

    for (int i = 1; i <= N; ++i) {
        int A;
        cin >> A;
        cur_sum += A;
    }

    for (int i = 0;; ++i) {
        int target_sum = X * (N + i);

        if ((cur_sum + (100 * i)) >= target_sum) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}