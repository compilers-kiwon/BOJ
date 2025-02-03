#include <iostream>
#include <cstdint>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    uint64_t N, sum;

    cin>>N;
    sum = 0;

    for (uint64_t i = 1; i <= N; i++) {
        sum += i * (N / i);
    }

    cout<<sum<<'\n';
    return 0;
}