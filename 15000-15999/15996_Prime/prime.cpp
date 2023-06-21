#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    int64   N,A,k,p;

    cin>>N>>A;

    for(p=A,k=0;p<=N;p*=A)
    {
        k += N/p;
    }

    cout<<k<<'\n';
    return  0;
}