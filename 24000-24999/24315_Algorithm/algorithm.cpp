#include <iostream>

using namespace std;

const int MAX_NUM = 100;

static inline bool in_range(int MIN, int n, int MAX) {
    return ((MIN<=n)&&(n<=MAX));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a1, a0, c1, c2, n0, result;

    result = 1;
    cin>>a1>>a0>>c1>>c2>>n0;

    for (int d = 0; d <= MAX_NUM * MAX_NUM; d++) {
        int n = n0 + d;

        if (!in_range(c1*n, a1*n+a0, c2*n)) {
            result = 0;
            break;
        }
    }

    cout<<result<<'\n';

    return 0;
}