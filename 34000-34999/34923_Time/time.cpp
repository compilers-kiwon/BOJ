#include <iostream>

using namespace std;

int get_minutes(void) {
    int hh, mm;
    char c;
    cin >> hh >> c >> mm;
    return ((hh % 12) * 60) + mm;
}

int simulate(int from, int to) {
    int ret = 0;

    for (int t = from; (t % 720) != to; t++) {
        ret += 6;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t1 = get_minutes();
    int t2 = get_minutes();

    cout << min(simulate(t1, t2), simulate(t2, t1)) << '\n';

    return 0;
}