#include    <iostream>

using namespace std;

typedef unsigned long long  uint64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    uint64  K,N;

    cin>>K>>N;

    if (N == 1) {
        cout<<"-1\n";
        return  0;
    }

    cout<<(K*N)/(N-1)+((K*N)%(N-1)==0?0:1)<<'\n';
    return  0;
}