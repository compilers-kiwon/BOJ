#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s,r;
    int     n0,n1,i;

    cin>>s;

    for (i=n0=n1=0;i<s.length();i++) {
        (s[i]=='0')?n0++:n1++;
    }

    n0 /= 2;
    n1 /= 2;

    for (int i=0;i<s.length();i++) {
        if (s[i] == '0') {
            if (n0 > 0) r.push_back('0'),n0--;
        } else {
            if (n1 > 0) n1--;
            else r.push_back('1');
        }
    }

    cout<<r<<'\n';
    return  0;
}