#include    <iostream>

using namespace std;

typedef unsigned long long  uint64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    uint64  N,sum;

    cin>>N;
    sum = 0;
    
    for(uint64 i=1;i<=N;i++)
    {
        sum += i*i*i;
    }

    cout<<sum<<'\n';

    return  0;
}