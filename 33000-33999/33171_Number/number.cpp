#include <iostream>

using namespace std;

static inline int is_divisible(int n, int m) {
    return ((n % m) == 0)?1:0;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, A, B, cnt;

    cnt = 0;
    cin>>N>>A>>B;

    for (int i = 1; i <= N; i++) {
        if ((is_divisible(i, A) + is_divisible(i, B)) == 1) {
            cnt++;
        }
    }

    cout<<cnt<<'\n';

    return 0;
}