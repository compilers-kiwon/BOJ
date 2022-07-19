#include    <iostream>

using namespace std;

typedef long long int    int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 V,N,shifted;

    cin>>V>>N;
    shifted = (V*N)*10;

    for(int64 i=1;i<=9;i++)
    {
        cout<<(shifted*i)/100LL+(((shifted*i)%100LL)==0LL?0LL:1LL)<<' ';
    }
    cout<<'\n';

    return  0;
}