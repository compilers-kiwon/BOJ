#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int int64;

#define MAX_SIZE (10000+1)

int N;
int64 t[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> t[i];
    }

    sort(&t[1], &t[N+1]);

    int64 M = 0;

    for (int s = (N%2==0)?1:0, e = N; s < e; ++s, --e) {
        M = max(M, t[s] + t[e]);
    }

    cout << M << '\n';

    return 0;
}