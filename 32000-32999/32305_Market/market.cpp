#include <iostream>

using namespace std;

const int num_of_price_unit = 12;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a, b, d;
    cin >> a >> b >> d;
    cout << (((a * b) + (num_of_price_unit - 1)) / num_of_price_unit) * d << '\n';

    return 0;
}