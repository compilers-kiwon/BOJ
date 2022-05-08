#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,f;

    cin>>n;
    f = 1;

    for(int i=1;i<=n;i++)
    {
        f = (f*i)%10;
    }

    cout<<f<<'\n';

    return  0;
}