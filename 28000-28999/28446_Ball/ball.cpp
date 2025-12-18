#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M;
    unordered_map<int, int> locker;

    for (cin >> M; M > 0; M--) {
        int n, x, w;

        cin >> n;

        if (n == 1) {
            cin >> x >> w;
            locker[w] = x;
        } else {
            cin >> w;
            cout << locker[w] << '\n';
        }
    }

    return 0;
}