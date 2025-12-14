#include <iostream>

using namespace std;

const int BASE_PRICE = 250;
const int EXTRA_CHARGE = 100;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int S, A, B, num_of_extra;

    cin >> S >> A >> B;
    for (num_of_extra = 0; A < S; A += B, num_of_extra++);
    cout << BASE_PRICE + (EXTRA_CHARGE * num_of_extra) << '\n';

    return 0;
}