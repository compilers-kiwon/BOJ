#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, min_fare, max_fare;

    cin >> N;
    min_fare = 0x7FFFFFFF;
    max_fare = 0;

    for (int i = 1; i <= N; i++) {
        int P;

        cin >> P;

        min_fare = min(min_fare, P);
        max_fare = max(max_fare, P);
    }

    cout << max(0, min_fare - (max_fare / 2)) << '\n';

    return 0;
}