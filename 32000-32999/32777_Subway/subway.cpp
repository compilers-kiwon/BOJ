#include <iostream>

using namespace std;

#define MAX_NUM_OF_STATIONS (43)
#define START_STATION (201)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;

    for (cin >> Q; Q > 0; Q--) {
        int a, b, inner, outer;

        cin >> a >> b;

        a -= START_STATION;
        b -= START_STATION;

        if (a < b) {
            inner = b - a;
            outer = (a + MAX_NUM_OF_STATIONS) - b;
        } else {
            inner = (b + MAX_NUM_OF_STATIONS) - a;
            outer = a - b;
        }

        if (inner == outer) {
            cout << "Same\n";
        } else {
            cout << ((inner < outer)?
                "Inner circle line\n":"Outer circle line\n");
        }
    }

    return 0;
}