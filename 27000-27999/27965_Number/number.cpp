#include <iostream>
#include <string>

using namespace std;

typedef long long int int64;

#define OFFSET (10LL)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, K, num, i;

    cin >> N >> K, num = 0LL, i = 1LL;

    for (int64 from = 1, to = OFFSET; i <= N; from *= OFFSET, to *= OFFSET) {
        for (i = from; i <= N && i < to; ++i) {
            num = (num * to + i) % K;
        }
    }

    cout << num << '\n';

    return 0;
}