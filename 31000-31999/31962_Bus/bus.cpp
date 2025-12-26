#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X, start;

    for (cin >> N >> X, start = -1; N > 0; N--) {
        int S, T;

        cin >> S >> T;

        if (S + T > X) {
            continue;
        }
        
        start = max(start,S);
    }

    cout << start << '\n';

    return 0;
}