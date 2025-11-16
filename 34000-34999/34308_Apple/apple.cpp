#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K, mid;

    cin >> N >> K;
    mid = (N + 1) / 2;

    for (int i = 1; i <= K; i++) {
        int n;
        cin >> n;
        cout << ((n<=mid)?1:N) << ((i==K)?'\n':' ');
    }

    return 0;
}