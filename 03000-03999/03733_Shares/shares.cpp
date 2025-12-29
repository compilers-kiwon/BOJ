#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int N, S; cin >> N >> S;) {
        cout << S / (N + 1) << '\n';
    }

    return 0;
}