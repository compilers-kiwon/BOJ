#include <iostream>

using namespace std;

const int UPPER_PREF_MINUTES = 4 * 60;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int S, Ma, Fab, Mb, t;

    cin >> S >> Ma >> Fab >> Mb;

    if (S <= UPPER_PREF_MINUTES || S <= (Ma + Fab + Mb)) {
        cout << "high speed rail\n";
    } else {
        cout << "flight\n";
    }

    return 0;
}