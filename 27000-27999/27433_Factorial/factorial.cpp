#include <iostream>
#include <cstdint>

using namespace std;

uint64_t get_factorial(uint64_t n) {
    if (n == 0) {
        return 1;
    }

    return n*get_factorial(n - 1);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    uint64_t N;

    cin>>N;
    cout<<get_factorial(N)<<'\n';

    return 0;
}