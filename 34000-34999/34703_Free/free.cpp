#include <iostream>

using namespace std;

#define NUM_OF_DAYS (5)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, busy, state;
    
    cin >> N, busy = state = 0;

    for (int d = 1; d <= NUM_OF_DAYS; ++d) {
        busy |= 1 << d;
    }

    for (int i = 1; i <= N; i++) {
        int d;
        cin >> d;
        state |= 1 << d;
    }

    cout << (state==busy?"NO":"YES") << '\n';

    return 0;
}