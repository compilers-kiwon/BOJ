#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, c, total_seconds;

    for (cin >> n >> c, total_seconds = 0; n >0; n--) {
        int m, ss;
        char _c;

        cin >> m >> _c >> ss;
        total_seconds += (m * 60) + ss - c;
    }

    total_seconds += c;

    int hh, mm, ss;

    hh = total_seconds / 3600;
    total_seconds %= 3600;

    mm = total_seconds / 60;
    ss = total_seconds % 60;

    cout << setw(2) << setfill('0') << hh << ':'
            << setw(2) << setfill('0') << mm << ':'
            << setw(2) << setfill('0') << ss << '\n';

    return 0;
}