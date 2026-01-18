#include <iostream>
#include <cstdint>

using namespace std;

#define MAX_SIZE (1000000+1)

typedef long long int int64;

int N;
int64 A[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

int is_ascending(void) {
    A[0] = INT64_MIN;

    for (int i = 1; i <= N; i++) {
        if (A[i] <= A[i-1]) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << is_ascending() << '\n';

    return 0;
}