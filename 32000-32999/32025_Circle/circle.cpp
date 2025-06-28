#include <iostream>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int H, W;

    std::cin>>H>>W;
    H *= 100, W *= 100;

    std::cout<<std::min(H/2, W/2)<<'\n';

    return 0;
}