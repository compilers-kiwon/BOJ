#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b;

    cin>>a>>b;
    cout<<(a*(100-b)<10000?1:0)<<'\n';

    return  0;
}