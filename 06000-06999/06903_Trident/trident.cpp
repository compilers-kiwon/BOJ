#include    <iostream>
#include    <string>

using namespace std;

#define print_tine(space) \
    {cout<<'*'<<string((space),' ')<<'*'<<string((space),' ')<<"*\n";}

#define print_handle(space) cout<<string((space),' ')<<"*\n"

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t,s,h;

    cin>>t>>s>>h;

    for(int i=1;i<=t;i++) print_tine(s);
    cout<<string(3+2*s,'*')<<'\n';
    for(int i=1;i<=h;i++) print_handle(1+s);

    return  0;
}