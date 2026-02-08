#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h, m;

    cin >> h >> m;
    
    for (int hh = 0; hh < 12; ++hh) {
        for(int mm = 0; mm < 60; mm += 2) {
            int hh_degree = (hh * 30) + (mm / 2);
            int mm_degree = mm * 6;

            if (hh_degree == h && mm_degree == m) {
                cout << "yes\n";
                return 0;
            }
        }
    }

    cout << "no\n";

    return 0;
}