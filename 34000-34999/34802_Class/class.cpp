#include <iostream>

using namespace std;

int get_time(void) {
    char c;
    int hh, mm, ss;

    cin >> hh >> c >> mm >> c >> ss;

    return (hh * 3600) + (mm * 60) + ss;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int s, e, t, k;

    s = get_time();
    e = get_time();
    cin >> t >> k;

    if ((s + (t * (100 - k) / 100)) <= e) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}