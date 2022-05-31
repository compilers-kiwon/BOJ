#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for(cin>>t;t>0;t--)
    {
        int64   x,y;

        cin>>x>>y;
        cout<<x+y<<'\n';
    }

    return  0;
}