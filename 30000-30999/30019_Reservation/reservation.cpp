#include <iostream>

using namespace std;

#define MAX_NUM_OF_ROOMS (200000+1)

int state[MAX_NUM_OF_ROOMS];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    for (cin >> N >> M; M > 0; M--) {
        int k, s, e;

        cin >> k >> s >> e;

        if (state[k] <= s) {
            cout << "YES\n", state[k] = e;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}