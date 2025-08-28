#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

typedef long long int int64;

int64 A[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int64 X, min_cost;

    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    min_cost = (A[1] * X) + (A[2] * X);

    for (int i = 2; i < N; i++) {
        min_cost = min(min_cost, (A[i] * X) + (A[i+1] * X));
    }

    cout << min_cost << '\n';
    return 0;
}