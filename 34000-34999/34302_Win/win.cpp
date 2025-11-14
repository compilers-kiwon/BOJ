#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt, longest;

    for (cin >> N, cnt = longest = 0; N > 0; N--) {
        int S, T;

        cin >> S >> T;
        cnt = (S>T)?cnt+1:0;
        longest = max(longest, cnt);
    }

    cout << longest << '\n';
    return 0;
}