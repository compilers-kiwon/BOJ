#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (1000+1)
#define MAX_TIREDNESS (200)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, P, A[MAX_SIZE], cnt;

    cin >> P >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(&A[1], &A[N+1]);
    cnt = 0;

    for (int i = 1; i <= N && P < MAX_TIREDNESS; i++) {
        P += A[i], cnt++;
    }

    cout << cnt << '\n';
    return 0;
}