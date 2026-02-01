#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y;
    
    for (cin >> X >> Y; X <= Y; X += 60) {
        cout << "All positions change in year " << X << '\n';
    }

    return 0;
}