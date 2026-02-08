#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; --T) {
        int N;
        cin >> N;
        cout << N % 2 << '\n';
    }

    return 0;
}