#include <iostream>
#include <string>

using namespace std;

bool simulate(const string& dish, const string& seat, size_t pos) {
    for (size_t i = 0; i < dish.length();
            i++, pos = (pos + 1) % seat.length()) {
        if (dish[i] == 'M' && seat[pos] == 'S') {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    string dish, seat;

    cin >> N >> M >> dish >> seat;

    for (size_t i = 0; i < seat.length(); i++) {
        if (simulate(dish, seat, i) == true) {
            cout << i + 1 << '\n';
            return 0; 
        }
    }

    cout << "EI SAA\n";
    return 0;
}