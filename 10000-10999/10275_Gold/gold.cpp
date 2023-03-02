#include    <iostream>

using namespace std;

typedef long long int   int64;

int simulate(int n,int64 a,int64 b)
{
    int     d;
    int64   g = 1LL<<n;

    for(d=0;;d++,g>>=1)
    {
        if( g<=min(a,b) && (a%g==0 && b%g==0) )
        {
            break;
        }
    }

    return  d;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int     n;
        int64   a,b;

        cin>>n>>a>>b;
        cout<<simulate(n,a,b)<<'\n';
    }

    return  0;
}