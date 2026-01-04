#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X, Y, R, A, B;

    cin >> N >> X >> Y >> R, A = B = 0;

    for (int i = 1; i <= N; i++) {
        int T;
        
        cin >> T;

        if (X - R == T || X + R == T) {
            B++;
        }

        if (X - R < T && T < X + R) {
            A++;
        }
    }

    cout << A << ' ' << B << '\n';

    return 0;
}