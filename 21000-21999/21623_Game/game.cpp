#include    <iostream>

using namespace std;

int k,n;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     r,s;

    cin>>k>>n;
    r=0;s=n;

    for(int i=1;i<=k;i++)
    {
        int a;

        cin>>a;
        
        if( a > s )
        {
            continue;
        }

        s -= a;

        if( s == 0 )
        {
            r++;
            if(i!=k)s=n;
        }
    }

    cout<<r<<'\n'<<s<<'\n';

    return  0;
}