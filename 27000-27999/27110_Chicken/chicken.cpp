#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, A, B, C;

    cin >> N >> A >> B >> C;
    cout << min(N, A) + min(N, B) + min(N, C) << '\n';

    return 0;
}