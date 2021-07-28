#include    <iostream>

using namespace std;

typedef unsigned long long  uint64;

#define MOD(n)  ((n)%1000000000)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(;t>0;t--)
    {
        uint64  n,v;

        cin>>n;
        v = 1;

        for(uint64 i=1;i<=n;i++)
        {
            for(v*=i;v%10==0;v/=10);
            v = MOD(v);
        }

        cout<<v%10<<'\n';
    }

    return  0;
}