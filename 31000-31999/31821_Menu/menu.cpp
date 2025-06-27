#include <iostream>

const int MAX_NUM_OF_ITEMS = 10;

int main(void) {
    int N, M, price[MAX_NUM_OF_ITEMS + 1], sum;

    std::cin>>N;

    for (int i = 1; i <= N; i++) {
        std::cin>>price[i];
    }

    std::cin>>M;
    sum = 0;

    for (int i= 1; i <= M; i++) {
        int B;
        
        std::cin>>B;
        sum += price[B];
    }

    std::cout<<sum<<'\n';

    return 0;
}