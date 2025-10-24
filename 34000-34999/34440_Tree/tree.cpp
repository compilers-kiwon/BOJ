#include <iostream>

using namespace std;

typedef long long int int64;

int64 f(int64 n) {
    if (n == 0) {
        return 1;
    }

    return (n * f(n - 1)); 
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, west;

    cin >> N, west = 0;

    for (int64 i = 1; i <= N; i++) {
        char c;
        cin >> c;
        west += (c=='W')?1:0;
    }

    cout << f(N) / (f(west) * f(N - west)) -1 << '\n';
    return 0;
}