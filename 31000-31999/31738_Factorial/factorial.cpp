#include <iostream>

typedef long long int int64;

int main(void) {
    int64 N, M, f;

    std::cin>>N>>M;

    if (N >= M) {
        std::cout<<"0\n";
        return 0;
    }

    f = 1;

    for (int64 i = 1; i <= N; i++) {
        f = (f * i) % M;
    }

    std::cout<<f<<'\n';

    return 0;
}