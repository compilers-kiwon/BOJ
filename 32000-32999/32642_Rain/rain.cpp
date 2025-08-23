#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int64 cur, sum;

    cin >> N;
    cur = sum = 0;

    for (int i = 1; i <= N; i++) {
        int r;

        cin >> r;
        cur += (r==1)?1:-1;
        sum += cur;
    }

    cout << sum << '\n';
    return 0;
}