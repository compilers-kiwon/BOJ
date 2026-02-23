#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE (200000+1)

typedef long long int int64;

int N;
int64 A[MAX_SIZE];

int64 input(void) {
    int64 sum = 0LL;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    return sum;
}

int64 simulate(int64 each) {
    int64 d, ret;

    d = ret = 0LL;

    for (int i = 1; i <= N; ++i) {
        d = A[i] + d - each;
        ret += abs(d); 
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 num_of_kits = input();
    cout << simulate(num_of_kits / (int64)N) << '\n';

    return 0;
}