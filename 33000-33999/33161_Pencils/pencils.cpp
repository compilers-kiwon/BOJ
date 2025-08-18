#include <iostream>

using namespace std;

const int PRICE = 5;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A;
    cin >> A;
    cout << A / PRICE << '\n';

    return 0;
}