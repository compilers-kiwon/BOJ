#include <iostream>

using namespace std;

const int PERFORMANCE_FACTOR = 3;

int get_performance(int competitor_price,
            int competitor_performace, int my_price) {
    return (PERFORMANCE_FACTOR *
                (competitor_performace * my_price)) / competitor_price;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;
    cout << get_performance(A, B, C) << '\n';

    return 0;
}