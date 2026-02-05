#include <iostream>

using namespace std;

void print_time(int minutes) {
    int hh = minutes / 60;
    int mm = minutes % 60;

    cout << ((hh<10)?"0":"") << hh << ':'
            << ((mm<10)?"0":"") << mm << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;

    for (cin >> Q; Q > 0; --Q) {
        int M, cur_minutes;

        cin >> M;
        ++M, cur_minutes = 354;

        for (; M > 0 && cur_minutes < 1440;) {
            M -= 50, cur_minutes += 12;
        }

        if (M > 0) {
            cout << "-1\n";
        } else {
            print_time(cur_minutes);
        }
    }

    return 0;
}