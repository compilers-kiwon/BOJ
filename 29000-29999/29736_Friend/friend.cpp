#include <iostream>
#include <string>

using namespace std;

static inline bool in_range(int MIN, int n, int MAX) {
    return ((MIN <= n) && (n <= MAX));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, K, X, lower, upper, cnt;

    cnt = 0;
    cin>>A>>B>>K>>X;
    
    lower = max(K - X, A);
    upper = min(K + X, B);

    for (int i = A; i <= B; i++) {
        if (in_range(lower, i, upper)) {
            cnt++;
        }
    }

    cout<<((cnt==0)?"IMPOSSIBLE":to_string(cnt))<<'\n';

    return 0;
}