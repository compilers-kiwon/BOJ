#include    <iostream>

using namespace std;

#define MOD(n,m)  ((n)%(m))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,r;

    r = 1;
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;

        if( n == 0 )
        {
            continue;
        }

        r = MOD(r*n,M);
    }

    cout<<MOD(r,M)<<'\n';

    return  0;
}