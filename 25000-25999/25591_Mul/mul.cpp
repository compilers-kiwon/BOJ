#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int n,m;

    cin>>n>>m;

    int a = 100-n;
    int b = 100-m;
    int c = 100-(a+b);
    int d = a*b;
    int q = d/100;
    int r = d%100;

    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<q<<' '<<r<<'\n';
    cout<<c+q<<' '<<r<<'\n';

    return  0;
}