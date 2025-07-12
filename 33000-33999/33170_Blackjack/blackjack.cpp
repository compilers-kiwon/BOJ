#include <iostream>

int main(void) {
    int A, B, C;

    std::cin >> A >> B >> C;
    std::cout << (((A + B + C) <= 21) ? 1 : 0) << '\n';

    return 0;
}