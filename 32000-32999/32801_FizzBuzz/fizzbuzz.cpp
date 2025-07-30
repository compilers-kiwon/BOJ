#include <iostream>

using namespace std;

typedef long long int int64;

enum {
    Fizz = 0,
    Buzz = 1,
    FizzBuzz = 2,
    MAX_STATE = 3
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 n, a, b;
    int cnt[MAX_STATE] = {0, };

    cin >> n >> a >> b;

    for (int64 i = 1; i <= n; i++) {
        if ((i % a) == 0 && (i % b) == 0) {
            cnt[FizzBuzz]++;
        } else if ((i % a) == 0) {
            cnt[Fizz]++;
        } else if ((i % b) == 0) {
            cnt[Buzz]++;
        }
    }

    for (int j = Fizz; j <= FizzBuzz; j++) {
        cout << cnt[j] << ' ';
    }

    return 0;
}