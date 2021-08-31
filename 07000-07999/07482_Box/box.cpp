#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    cout<<fixed;
    cout.precision(10);

    for(int i=1;i<=n;i++)
    {
        long double a;

        cin>>a;
        cout<<a/6.0<<'\n';
    }

    return  0;
}