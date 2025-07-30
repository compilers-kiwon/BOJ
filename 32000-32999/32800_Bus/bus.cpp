#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, cur_occupied, max_seats;

    for (cin >> n, cur_occupied = max_seats = 0; n > 0; n--) {
        int a, b;
        cin >> a >> b;
        max_seats = max(max_seats, (cur_occupied += b - a));
    }

    cout << max_seats << '\n';

    return 0;
}