#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  a,b,c;

    cin>>a>>b;
    for (int i=0;i<a.length();i++) c.push_back(max(a[i],b[i]));

    cout<<c<<'\n';
    return  0;
}