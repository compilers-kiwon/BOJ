#include    <iostream>

using namespace std;

int get_gcd(int n1,int n2)
{
    int small = min(n1,n2);
    int big = max(n1,n2);

    for(int mod=big%small;mod!=0;mod=big%small)
    {
        big = small;
        small = mod;
    }

    return  small;
}

int get_henry(int a,int b)
{
    if( a == 1 )
    {
        return  b;
    }

    int x = (b/a)+(b%a?1:0);
    int gcd = get_gcd(a*x-b,b*x);

    return  get_henry((a*x-b)/gcd,(b*x)/gcd);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int a,b;

        cin>>a>>b;
        cout<<get_henry(a,b)<<'\n';
    }

    return  0;
}