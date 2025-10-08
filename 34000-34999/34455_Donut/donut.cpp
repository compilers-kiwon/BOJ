#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int D, E, R;

    cin >> D >> E;

    for (R = D; E > 0; E--) {
        char e;
        int Q;

        cin >> e >> Q;
        R += (e=='-')?-Q:Q;
    }

    cout << R << '\n';
    return 0;
}