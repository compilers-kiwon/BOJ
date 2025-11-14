#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int R, S, N, sum;

    cin >> R >> S >> N, sum = 0;

    if (R == 0) {
        cout<< "0\n";
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        int A;

        cin >> A;
        sum = (sum + A) % S;

        if (sum == R) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}