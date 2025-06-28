#include <iostream>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int n, p;

    std::cin>>n;
    p = 0;

    for (int i = 1; i <= n; i++) {
        int d;

        std::cin>>d;
        p += d;
    }

    std::cout<<p<<'\n';

    return 0;
}