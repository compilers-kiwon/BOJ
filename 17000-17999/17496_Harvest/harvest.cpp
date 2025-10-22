#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, T, C, P, profit;

    cin >> N >> T >> C >> P;
    profit = 0;

    for (int i = T + 1; i <= N; i += T) {
        profit += C * P;
    }

    cout << profit << '\n';

    return 0;
}