#include <iostream>
#include <string>

using namespace std;

#define MAX_DIFF (25)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X, cur_diff, pos;

    cin >> N >> X;
    cur_diff = X - N;

    string currency(N, 'A');

    for (int i = N - 1; i >= 0 && cur_diff > 0; i--) {
        int d = min(MAX_DIFF, cur_diff);
        currency[i] += d;
        cur_diff -= d;
    }

    cout << ((cur_diff==0)?currency:"!") << '\n';

    return 0;
}